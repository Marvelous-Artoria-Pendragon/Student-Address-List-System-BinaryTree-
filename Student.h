/*学生类*/
/*
历史版本： v1.0
          v2.0 出生日期使用unsigned 存储
          v3.0 重载姓名、学号、电话号码与关键码判等于的操作符；
              重载生日与关键码的三个判断操作符
当前版本： v3.0
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

struct Student
{
    Student() {};
    Student(const Student &s);                      //拷贝构造函数
    char name[21];                                  //姓名(20位字符)
    char sex[3];                                    //性别：男/女
    char number[21];                                //学号(20位数字)
    unsigned birthday;                              //出生日期：1~23位存储年份，24~27存储月份，28~32存储日期
    char phonenum[12];                              //手机号
    char addr[50];                                  //地址
    bool operator == (const char key[21]);                //重载姓名、学号、电话号码与关键码判等于
    bool operator > (const unsigned &key);                //重载生日与关键码判大于
    bool operator == (const unsigned &key);               //重载生日与关键码判等于
    bool operator < (const unsigned &key);                //重载生日与关键码判小于
    friend ostream &operator << (ostream &out, const Student &s);           //重载输出流，输出一个学生的所有信息
    friend istream &operator >> (istream &in, Student &s);                  //重载输入流，输入一个学生的所有信息
};
#endif //STUDENT_H