#include "BookData.h"
#include <vector>
#ifndef BOOK_BOOKOP_H
#define BOOK_BOOKOP_H

#endif //BOOK_BOOKOP_H

class BookOp {
private:
    const char* filePath ="data.txt";
    std::vector<BookData> bookList;   //书列表，暂时不使用
public:
    BookOp()   //无参数的构造函数
    {

    }
    BookOp(const char* filePath)   //带参数的初始化，初始化参数为文件保存路径filePath
    {
        this->filePath = filePath;
    }
    void SetFilePath(const char *filePath)  //如果之前没初始化文件路径，后面也可以通过Set方法去设置
    {
        this->filePath = filePath;
    }
    void InitFile(const char *filePath,int warnFlag);   //使用文件路径去初始化文件
    void Append();  // 新书入库
    void AddOld(int addFlag);  // 旧书入库/出库
    BookData QueryByNo();   // 根据书的No进行查询
    void Delete();   //根据ID删除数目
    void PrintAll();  //打印全部内容
    std::vector<BookData> TranformToVector();
};

void BookOp::InitFile(const char *filePath, int warnflag) {  //
    if(warnflag == 0)
    {
        FILE *fp;
        fp = fopen(filePath, "w");   //以写的方式打开
        fprintf(fp, "%s %s %s\n", "No", "Name", "Bal");
        fclose(fp);
    }
    else
    {
        printf("您是否要进行初始化？初始化将会覆盖您之前的文件哟！(Y/N)\n");
        char getCommand;
        std::cin>>getCommand;
        if(getCommand == 'Y' || getCommand == 'y')
        {
            FILE *fp;
            fp = fopen(filePath, "w");   //以写的方式打开
            fprintf(fp, "%s %s %s\n", "No", "Name", "Bal");
            printf("文件(%s)初始化成功",filePath);
            fclose(fp);
        }
        else
        {

        }
    }

}

void BookOp::Append() {  //新书入库
    int no;
    char name[40];
    long bal;
    printf("----------------请依次输入需要入库的书号，书名，书库存量-----------------\n");
    printf("书号(No)：");
    std::cin >> no;
    printf("书名(Name)：");
    std::cin >> name;
    printf("书库存(Balance)：");
    std::cin >> bal;
    BookData bookData;
    bookData.SetBalance(bal);
    bookData.SetBookName(name);
    bookData.SetBookNo(no);
    FILE *fp;
    fp = fopen(filePath, "a+");   //以append的方式读文件
    fprintf(fp, "%d %s %ld\n", bookData.GetBookNo(), bookData.GetBookName(), bookData.GetBalance());
    printf("**********该书目已经入库成功\n");
    fclose(fp);
}

void BookOp::AddOld(int addFlag) {
    FILE *fp;  //文件指针
    fp = fopen(filePath, "r");  //以只读的方式去读写文件

    FILE *fp1;   //生成一个临时文件，最终会改名为filePath
    char fpath[20] = "data111.txt";
    this->InitFile(fpath,0);  //初始化生成Title
    fp1 = fopen(fpath, "a+");  //以append的方式去操作文件

    char a[40];
    fscanf(fp, "%s %s %s", a, a, a);  //去掉第一行的Title，不需要
    int no = 0;  //书籍号，用来初始化
    char name[40];  //书籍名
    long bal = 0;  //书籍的库存量
    BookData bookData;  //书籍的类对象，用来返回
    int bno;  //用来输入以进行查找
    std::cout << "请输入书号：";
    std::cin >> bno;
    while (true) {

        fscanf(fp, "%d %s %ld", &no, name, &bal);  //读文件，扫描进对应的变量里
        if (feof(fp)) {  //如果遍历完，关闭文件指针，并结束循环
            fclose(fp1);
            break;
        }
        if (no == bno) {  //如果找到对应的书号，设置返回的对象
            printf("当前信息为：No:%d,Name:%s,Bal:%ld\n", no, name, bal);
            printf("请输入需要书号为%d入库的数量：", no);
            long num;
            std::cin >> num;
            if (addFlag == 1)  //如果flag=1，加，否则，减
            {
                bal += num;
            } else {
                bal -= num;
            }
            bookData.SetBookNo(no);
            bookData.SetBookName(name);
            bookData.SetBalance(bal);
            printf("修改后的信息是：No:%d,Name:%s，Bal:%ld\n", no, name, bal);
            fprintf(fp1, "%d %s %ld\n", no, name, bal);
            fflush(fp);
        } else {
            fprintf(fp1, "%d %s %ld\n", no, name, bal);
        }

    }
    remove(filePath);   //删除之前的文件
    rename(fpath, filePath);  //将临时文件替换掉之前的文件
}

BookData BookOp::QueryByNo() {  //return查找到的书的类对象
    FILE *fp;  //文件指针
    fp = fopen(filePath, "r");  //以只读的方式去读写文件
    char a[40];
    fscanf(fp, "%s%s%s", a, a, a);  //去掉第一行的Title，不需要
    int no = 0;  //书籍号，用来初始化
    char name[40];  //书籍名
    long bal = 0;  //书籍的库存量
    BookData bookData;  //书籍的类对象，用来返回
    int bno;  //用来输入以进行查找
    std::cout << "请输入书号：";
    std::cin >> bno;
    while (true) {
        fscanf(fp, "%d %s %ld", &no, name, &bal);  //读文件，扫描进对应的变量里
        if (no == bno || feof(fp)) {  //如果找到了，或者读取到最后都没找到，后面分类讨论
            break;
        }
    }
    if (no == bno) {  //如果找到对应的书号，设置返回的对象
        bookData.SetBookNo(no);
        bookData.SetBookName(name);
        bookData.SetBalance(bal);
        printf("No:%d,Name:%s,Bal:%ld\n", no, name, bal);
    } else  //如果没找到删掉信息
    {
        printf("没找到对应的书籍！\n");
    }
    return bookData;
}

void BookOp::Delete() {  //return查找到的书的类对象
    FILE *fp;  //文件指针
    fp = fopen(filePath, "r");  //以只读的方式去读写文件

    FILE *fp1;   //生成一个临时文件，最终会改名为filePath
    char path[20] = "data1.txt";
    this->InitFile(path,0);  //初始化生成Title
    fp1 = fopen(path, "a+");  //以append的方式去操作文件

    char a[20];
    fscanf(fp, "%s%s%s", a, a, a);  //去掉第一行的Title，不需要
    int no = 0;  //书籍号，用来初始化
    char name[40];  //书籍名
    long bal = 0;  //书籍的库存量
    BookData bookData;  //书籍的类对象，用来返回
    int bno;  //用来输入以进行查找
    std::cout << "请输入书号：";
    std::cin >> bno;
    while (true) {
        fscanf(fp, "%d %s %ld", &no, name, &bal);  //读文件，扫描进对应的变量里
        if (feof(fp)) {  //如果遍历完，关闭文件指针并结束循环
            fclose(fp1);
            break;
        }
        if (no == bno) {  //如果找到对应的书号，设置返回的对象
            bookData.SetBookNo(no);
            bookData.SetBookName(name);
            bookData.SetBalance(bal);
            printf("成功删除记录：No:%d,Name:%s,Bal:%ld\n", no, name, bal);
        } else {
            fprintf(fp1, "%d %s %ld\n", no, name, bal);
        }

    }
    remove(filePath);   //删除之前的文件
    rename(path, filePath);  //将临时文件替换掉之前的文件
}

void BookOp::PrintAll() {   //打印文件中的信息
    FILE *fp = fopen(filePath,"r");
    char Ta[10],Tb[10],Tc[10];   //标题的三个属性列名
    fscanf(fp,"%s\t%s\t%s",Ta,Tb,Tc);  //读出来列名
    printf("%s %s %s\n",Ta,Tb,Tc);  //打印列名
    /**
     * no,name,bal用于后面将数据扫描出来
     */
    int no;
    char name[40];
    long bal;
    while (true)
    {
        fscanf(fp,"%d %s %ld",&no,name,&bal);  //扫描文件中的具体数目
        if(feof(fp))  //如果读完了，就结束循环
        {
            break;
        }
        printf("%d\t%s\t%ld\n",no,name,bal);  //打印文件中的具体内容
    }
}

std::vector<BookData> BookOp::TranformToVector() {
    this->bookList.clear();   //清空向量，重新生成
    FILE *fp = fopen(filePath,"r");
    char Ta[10],Tb[10],Tc[10];   //标题的三个属性列名
    fscanf(fp,"%s\t%s\t%s",Ta,Tb,Tc);  //读出来列名
    printf("%s %s %s\n",Ta,Tb,Tc);  //打印列名
    /**
     * no,name,bal用于后面将数据扫描出来
     */
    int no;
    char name[40];
    long bal;

    BookData bookData;
    while (true)
    {
        fscanf(fp,"%d %s %ld",&no,name,&bal);  //扫描文件中的具体数目
        if(feof(fp))  //如果读完了，就结束循环
        {
            break;
        }
        bookData.SetBalance(bal);
        bookData.SetBookName(name);
        bookData.SetBookNo(no);
        this->bookList.insert(this->bookList.end(),bookData);  //将新的元素放入向量中
        printf("%d\t%s\t%ld\n",no,name,bal);  //打印文件中的具体内容
    }
     return this->bookList;
}


