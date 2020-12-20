#include <iostream>
#include "BookOp.h"

using namespace std;

int main() {
    char filePath[20] = "data.txt";
    BookOp op;
    op.SetFilePath(filePath);   //设置存储的文件默认的路径
    while (1) {
        printf("--------------------请输入对应的号码进行对应的操作---------------------\n");
        printf("0->初始化文件\t1-旧书入库\t2->新书入库\t3->查询书籍\n4->删除书籍\t5->打印全部\t6-转换成向量\tQ/q->退出\n");
        char getCommand;  //保存用户的输入命令
        cin >> getCommand;   //输入command
        if (getCommand == '0') {
            op.InitFile(filePath,1);
            continue;
        } else if (getCommand == '1') {
            printf("入库/出库，入库请输入1，出库请输入2\n");
            int Addflag;
            std::cin>>Addflag;
            op.AddOld(Addflag);
            continue;
        } else if (getCommand == '2') {
            op.Append();
            continue;
        } else if (getCommand == '3') {
            op.QueryByNo();
            continue;
        } else if (getCommand == '4') {
            op.Delete();
            continue;
        } else if(getCommand == '5')
        {
            op.PrintAll();
        } else if(getCommand == '6')
        {
            op.TranformToVector();
        }
        else if (getCommand == 'Q' || getCommand == 'q') {  //如果是Q/q，退出
            return 0;
        } else {
            printf("!!!!!!!!!!!!!!输入错误，请重新输入\n");
            continue;
        }
    }
}
