/*
项目名：学生通讯录管理系统
作者：何子浩
最新修改日期：2020/11/22
版本历史信息：v1.0              构建基本框架
             v2.0              修复了二叉树寻找编号为n的结点算法的bug
                               文件读写路径改为输入获取
当前版本号：v2.0
*/
#ifndef MENU_CPP
#define MENU_CPP
#include "Student.h"        //Student类
#include "System.h"         //System类
#include "kit.h"

int main()
{
    short op;                                 //输入的操作选项
    System<Student> p;                        //学生健康表
    void (System<Student>::*option[11])() = {&System<Student>::create, &System<Student>::insert, &System<Student>::searchByNumber,
                &System<Student>::searchByName, &System<Student>::searchByPhonenum, &System<Student>::del,
                &System<Student>::displayYoungestStudent, &System<Student>::display, &System<Student>::readFromFile, 
                &System<Student>::writeToFile, &System<Student>::createData};
    cout << "**************学生通讯录管理系统***************\n";
    while (1)
    {
        cout << "=========================================\n"
            << "系统的菜单功能项如下：\n"
            << "1------新建学生健康表\n"
            << "2------向学生通讯录插入学生信息\n"
            << "3------在通讯录中查询学生信息(按学号查询)\n"
            << "4------在通讯录中查询学生信息(按姓名查询)\n"
            << "5------在通讯录中查询学生信息(按电话号码查询)\n"
            << "6------在通讯录删除学生信息\n"
            << "7------输出年龄最小的学生信息\n"
            << "8------在屏幕中输出全部学生信息\n"
            << "9------从文件中读取通讯录信息\n"
            << "10-----向文件写入学生通讯录信息\n"
            << "11-----生成数据集\n"
            << "12-----退出\n"
            << "=========================================\n";
        getData(op, "[1-9]|([1][0-2])", "执行的操作"); cout << endl;
        if (op == 12) exit(0);
        (p.*option[op - 1])();
    }
}
#endif //MENU_CPP