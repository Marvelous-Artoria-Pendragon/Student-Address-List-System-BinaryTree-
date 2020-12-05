#ifndef SYSTEM_H
#define SYSTEM_H
#include "CompleteBinaryTree.h"
#include <iostream>
#include <fstream>
#include "kit.h"
#include <stdio.h>
#include <ctime>
using namespace std;

template <class T>
class System                                            //系统类
{
    protected:
        CompleteBinaryTree<T> *bt;                          //二叉树根结点指针
        template <typename Y>
        friend void getData(Y &, string, string, string);   //获取指定格式的数据函数
    public:
        System(): bt(new CompleteBinaryTree<T>){}           //构造函数,默认没有初始值
        //System(const System<T> &);                        //拷贝构造函数
        ~System(){delete bt;}                               //析构函数
        
        void create();                                      //新建学生通讯录(以层次遍历的方式进行学生信息的输入)
        void insert();                                      //向学生通讯录插入学生信息
        void searchByNumber();                              //在通讯录中查询学生信息（按学号查询）
        void searchByName();                                //在通讯录中查询学生信息（按姓名查询）
        void searchByPhonenum();                            //在通讯录中查询学生信息（按电话号码查询）
        void del();                                         //在通讯录删除学生信息（先按上述3-5的查询方式定位被删除学生）
        void displayYoungestStudent();                      //输出年龄最小的学生信息
        void display();                                     //在屏幕中输出全部学生信息（可以选择是以前序、中序、后序遍历的方式）
        void readFromFile();                                //从文件中读取通讯录信息
        void writeToFile();                                 //向文件写入通讯录信息
        void createData();                                  //生成n个数据
};

//新建学生通讯录(以层次遍历的方式进行学生信息的输入)
template <class T>
void System<T>::create()
{
    int n; getData(n, "\\d+", "创建的学生数");  
    if (n < 1) cout << "*******************新建失败，创建通讯录人数至少为1！*********************" << endl;
    else {bt->CreateBinTree(cin, n); cout << "新建成功！" << endl;}
}

//向学生通讯录插入学生信息
template <class T>
void System<T>::insert()
{
    clock_t startTime, endTime; T item; cin >> item;
    startTime = clock(); bt->insert(item);              //计时开始
    cout << "************************插入成功！**********************" << endl;
    endTime = clock();                 //计时结束
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//在通讯录中查询学生信息（按学号查询）
template <class T>
void System<T>::searchByNumber()
{
    clock_t startTime, endTime;
    if (bt->isEmpty()) {cout << "*****************************当前未有任何通讯录记录！****************************\n"; return;}
    char number[21]; getData(number, "\\d{1,20}", "请输入学生学号"); startTime = clock();                //计时开始
    BinTreeNode<T> *temp = bt->find(number);
    if (temp != NULL) cout << "已找到：\n" << temp->data << endl;
    else cout << "************************未找到该学生！**************************" << endl;
    endTime = clock();                 //计时结束
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//在通讯录中查询学生信息（按姓名查询）
template <class T>
void System<T>::searchByName()
{
    clock_t startTime, endTime;
    if (bt->isEmpty()) {cout << "*****************************当前未有任何通讯录记录！****************************\n"; return;}
    char name[21]; getData(name, "[^\\d]{1,20}", "请输入学生姓名"); startTime = clock();                //计时开始
    BinTreeNode<T> *temp = bt->find(name);
    if (temp != NULL) cout << "已找到：\n" << temp->data << endl;
    else cout << "************************未找到该学生！**************************" << endl;
    endTime = clock();                 //计时结束
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//在通讯录中查询学生信息（按电话号码查询）
template <class T>
void System<T>::searchByPhonenum()
{
    clock_t startTime, endTime;
    if (bt->isEmpty()) {cout << "*****************************当前未有任何通讯录记录！****************************\n"; return;}
    char phonenum[12]; getData(phonenum, "\\d{11}", "请输入学生的电话号码"); startTime = clock();                //计时开始
    BinTreeNode<T> *temp = bt->find(phonenum);
    if (temp != NULL) cout << "已找到：\n" << temp->data << endl;
    else cout << "************************未找到该学生！**************************" << endl;
    endTime = clock();                 //计时结束
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//在通讯录删除学生信息（先按上述3-5的查询方式定位被删除学生）
template <class T>
void System<T>::del()
{
    if (bt->isEmpty()) {cout << "*****************************当前未有任何通讯录记录！****************************\n"; return;}
    cout << "1----------------学号\n" << "2----------------姓名\n" << "3----------------电话号码\n";
    int op = 0; getData(op, "[1-3]", "请选择删除的学生的信息"); bool flag = false;                              //删除成功标识
    clock_t startTime, endTime;
    char data[3][21]; getData(data[op - 1], ".{1,20}");             //存储输入数据的字符数组
    startTime = clock();                //计时开始
    if (bt->remove(data[op - 1])) {cout << "**************************删除成功！****************************" << endl;}
    else cout << "***********************未找到该学生的记录，删除失败！***************************" << endl;
    endTime = clock();                 //计时结束
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//输出年龄最小的学生信息
//使用层次遍历和选择法寻找年龄最小的学生
template <class T>
void System<T>::displayYoungestStudent()
{
    if (bt->isEmpty()) {cout << "*******************当前通讯录未有任何记录！*******************\n" << endl; return;}   //根为空提示
    clock_t startTime, endTime;
    startTime = clock();                //计时开始
    BinTreeNode<T> *root = bt->getRoot(), *temp = NULL, *youngest = root;             //根结点和年龄最小的学生所在结点
    LinkedQueue<BinTreeNode<T> *> Q; Q.EnQueue(root);
    while (!Q.isEmpty())
    {
        Q.DeQueue(temp);
        if (temp->data.birthday > youngest->data.birthday) youngest = temp;
        if (temp->child[0] != NULL) Q.EnQueue(temp->child[0]);                    //左子女进队
        if (temp->child[1] != NULL) Q.EnQueue(temp->child[1]);                    //右子女进队
    }
    cout << "年龄最小的学生：\n" << youngest->data << endl;
    endTime = clock();                 //计时开始
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//在屏幕中输出全部学生信息（可以选择是以前序、中序、后序遍历的方式）
template <class T>
void System<T>::display()
{
    if (bt->isEmpty()) {cout << "************未有任何通讯录信息！**************" << endl; return;}
    cout << "1----前序遍历\n" << "2----中序遍历\n" << "3----后序遍历\n";
    void (CompleteBinaryTree<T>::*arr[3])(void (*visit)(BinTreeNode<T> *current)) 
            = {&CompleteBinaryTree<T>::preOrder, &CompleteBinaryTree<T>::inOrder, &CompleteBinaryTree<T>::postOrder};
    int op; getData(op, "[1-3]", "遍历方式");
    static unsigned index = 0;                              //标识学生人数
    (bt->*arr[op - 1])([](BinTreeNode<T> *current) {cout << "第" << ++index << "个学生：\n" << current->data << endl;});
    index = 0;                                              //重置学生人数
}

//从文件中读取通讯录信息
template <class T>
void System<T>::readFromFile()
{
    clock_t startTime, endTime;
    char path[1000]; getString(path, ".+\\..+", "文件名");
    startTime = clock();                //计时开始
    if (bt->load(path)) cout << "****读取成功！****" << endl;
    else cout << "***********************文件打开失败！*************************" << endl;
    endTime = clock();                 //计时结束
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//向文件写入通讯录信息
template <class T>
void System<T>::writeToFile()
{
    clock_t startTime, endTime;
    char path[1000]; getString(path, ".+\\..+", "文件名");
    startTime = clock();                //计时开始
    if (bt->save(path)) cout << "****读取成功！****" << endl;
    else cout << "***********************文件新建失败！*************************" << endl;
    endTime = clock();                 //计时结束
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//生成n个数据
template <class T>
void System<T>::createData()
{
    unsigned n; getData(n, "\\d+", "生成数量"); T stu;
    char path[1000]; getString(path, ".+\\..+", "数据集文件名");
    ofstream outfile(path, ios::out | ios::binary);
    char version[] = "0xA0B0C0";                                           //标志文件是否有效
    outfile.write(version, 8);
    if (!outfile) {cerr << "**********************文件打开失败！**********************" << endl; return;}      //文件打开失败
    clock_t startTime, endTime;
    startTime = clock();                //计时开始
    const unsigned STU_SIZE = sizeof(stu);                                 //结构体大小
    for (int i = 1; i <= n; i++)
    {
        snprintf(stu.name, 21, "%d", i);
        snprintf(stu.sex, 3, "%s", "男");
        snprintf(stu.number, 21, "%d", i);
        stu.birthday = i;
        snprintf(stu.phonenum, 12, "12345678901");
        snprintf(stu.addr, 21, "beijing");
        outfile.write((char *) &stu, STU_SIZE);
    }
    endTime = clock();                //计时开始
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    outfile.close();
    cout << "***********************数据创建成功！***********************" << endl;
}
#endif //SYSTEM_H