### 项目组成
#### 1.BookData.h
用来存放项目中用到的实体类对象--Book <br />
定义了书的属性：No、Name、Balance <br />
对每个字段都设置成为了私有属性，设置了Getter和Setter去读写每个字段 <br />
#### 2.BookOp.h
用来存放一些对书的操作
用到的方法如下：
```cpp
void InitFile(const char *filePath,int warnFlag);   //使用文件路径去初始化文件
void Append();  // 新书入库
void AddOld(int addFlag);  // 旧书入库/出库
BookData QueryByNo();   // 根据书的No进行查询
void Delete();   //根据ID删除数目
void PrintAll();  //打印全部内容
std::vector<BookData> TranformToVector();  //将文本中的内容转换为向量的形式
```
InitFile方法主要用来实现对文本文件的初始化（即添加对应的标题）<br />
Append方法用来向文本文件中新增一个数目 <br />
AddOld方法用于设置旧书的入库/出库，addFlag==1为入库 <br />
QueryByNo方法用于通过书的编号No去查询信息<br />
Delete方法主要用来删除文件中的某个书目 <br />
PrintAll方法用来打印当前书库中的书目信息 <br />
TransformToVector方法用来将当前书库中的书目转换为向量<br />

#### main.cpp
用来打印主菜单，引导用户进行操作，输入对应的命令能够进行对应的操作 <br>

### 项目的运行
#### Way1
1.使用IDE-IntelliJ Clion直接打开项目，点击右上角的三角形运行<br />
#### Way2
2.安装GCC编译器，使用gcc main.cpp -o main进行编译，再使用./main命令进行执行<br />
#### Way3
3.使用其他编译器，如Visual Studio，
创建项目-拷贝main文件到项目主文件
新建两个头文件BookOp.h和BookData.h，
将项目中的两个文件对应内容拷贝过去就行<br />
