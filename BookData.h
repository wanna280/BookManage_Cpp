#include <iostream>
#include <fstream>
#include <string.h>

#ifndef BOOK_BOOKDATA_H
#define BOOK_BOOKDATA_H

#endif //BOOK_BOOKDATA_H

class BookData
{
private:
    int bookNo;           //书的编号
    const char *bookName; //书名
    long balance;         //库存量
public:
    BookData();                                               //空的构造函数
    BookData(int bookNo, const char *bookName, long balance); //带参数的构造函数
    ~BookData();                                              //析构函数
    int GetBookNo();                                          //书的编号的Getter
    bool SetBookNo(int bookNo);                               //书编号的Setter
    const char *GetBookName();                                //书名的Getter，//注意加const，不加会有warning
    bool SetBookName(const char *bookName);                   //书名的Setter
    long GetBalance();                                        //库存量的Getter
    bool SetBalance(long balance);                            //库存量的Setter
};

BookData::BookData()   //空构造函数
{
}

BookData::BookData(int bookNo, const char *bookName, long balance)  //带参数的构造函数
{
    this->bookNo = bookNo;
    this->bookName = bookName;
    this->balance = balance;
}

BookData::~BookData()
{
}
int BookData::GetBookNo()  //获取书的编号
{
    return this->bookNo;
}
const char *BookData::GetBookName()  //获取书名
{
    return this->bookName;
}

long BookData::GetBalance()  //获取库存
{
    return this->balance;
}

bool BookData::SetBookNo(int bookNo)  //设置书的编号
{
    this->bookNo = bookNo;
    return true;
}

bool BookData::SetBookName(const char *bookName)  //设置书的名字
{
    this->bookName = bookName;
    return true;
}

bool BookData::SetBalance(long balance)  //设置书的库存
{
    this->balance = balance;
    return true;
}