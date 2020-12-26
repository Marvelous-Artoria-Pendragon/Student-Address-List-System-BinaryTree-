#include "Student.h"
#include <string.h>

//拷贝构造函数
Student::Student(const Student &s)
{
    strcpy_s(name, s.name);
    strcpy_s(sex, s.sex);
    strcpy_s(number, s.number);
    birthday = s.birthday;
    strcpy_s(phonenum, s.phonenum);
    strcpy_s(addr, s.addr);
}


//重载输入流，输入一个学生的所有信息
//istream &operator >> (istream &in, Student &s)
//{
//    getData(s.name, ".{1,20}", "姓名");
//    getData(s.sex, "\\W{2}", "性别(男/女)");
//    getData(s.number, "\\d{1,20}", "学号(最长20位)");            //最大读取20位数字
//    unsigned temp = 0;
//    getData(temp, "\\d+", "出生年份"); s.birthday = temp;
//    getData(temp, "[1-9]|([1][0-2])", "出生月份");
//    s.birthday = (s.birthday << 4) + temp;
//    getData(temp, "([1-2][0-9])|([1-9])|([3][0-1])", "出生日期");
//    s.birthday = (s.birthday << 5) + temp;
//    getData(s.phonenum,  "\\d{11}", "手机号(11位)");
//    getData(s.addr, ".{1,100}", "地址");
//    return in;
//}

//重载姓名和学号与关键码判等于
bool Student::operator == (const char key[21])
{return strcmp(name, key) == 0 || strcmp(number, key) == 0 || strcmp(phonenum, key) == 0 ? true : false;}

//重载生日与关键码判大于
bool Student::operator > (const unsigned &key) {return birthday > key ? true : false;}

//重载生日与关键码判等于
bool Student::operator == (const unsigned &key) {return birthday == key ? true : false;}

//重载生日与关键码判小于
bool Student::operator < (const unsigned &key) {return birthday > key ? true : false;}

//重载生日与关键码判大于(右值为类成员)
bool operator > (const unsigned &key, const Student &s) {return key > s.birthday ? true : false;}

//重载生日与关键码判等于(右值为类成员)
bool operator == (const unsigned &key, const Student &s) {return key == s.birthday ? true : false;}

//重载生日与关键码判小于(右值为类成员)
bool operator < (const unsigned &key, const Student &s) {return key < s.birthday ? true :false;}

//学生之间按年龄比较：大于
bool operator > (const Student &s1, const Student &s2) {return s1.birthday > s2.birthday ? true : false;}

//学生之间按年龄比较：等于
bool operator == (const Student &s1, const Student &s2) {return s1.birthday == s2.birthday ? true : false;}

//学生之间按年龄比较：大于
bool operator < (const Student &s1, const Student &s2) {return s1.birthday < s2.birthday ? true : false;}
