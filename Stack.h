#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>
using namespace std;
//const int STACK_INCREASMENT = 20;           //栈溢出时扩展空间的增量
//const int MAX_SIZE = 50;

template <class T>
class Stack
{
    public:
        Stack(){};  //构造函数
        virtual void push(const T &x) = 0;      //新元素x进栈
        virtual bool pop(T &x) = 0;             //栈顶元素出栈，由x返回
        virtual bool getTop(T &x) const = 0;    //读取栈顶元素，由x返回
        virtual bool isEmpty() const = 0;       //判断栈是否为空
        virtual bool isFull() const = 0;        //判断栈是否为满
        virtual int getSize() const = 0;        //计算栈中元素个数
};

//顺序栈
template <class T>
class SeqStack: public Stack<T>
{
    public:
        SeqStack(int sz = 50);                              //建立一个空栈
        ~SeqStack() {delete[] elements;}                    //析构函数
        virtual void push(const T &x);                      //如果isFull(),则溢出处理；否则把x插入到栈的栈顶
        virtual bool pop(T &x);                             //取出栈顶元素，赋值给x
        virtual bool getTop(T &x) const;                    //获取栈顶元素的拷贝给x，不删除栈顶元素
        virtual bool isEmpty() const {return (top == -1) ? true:false;}             
        virtual bool isFull() const {return (top == maxSize - 1) ? true:false;}
        virtual int getSize() const {return top + 1;}
        void makeEmpty() {top = -1;}                        //清空栈的内容
        //输出栈中元素的操作
        template <class Y>
        friend ostream &operator <<(ostream &os, SeqStack<Y> &s);
    private:
        T *elements;                //存放栈中元素的栈数组
        int top;                    //栈顶指针
        int maxSize;                //栈最大可容纳元素个数
        void overflowProcess();     //栈溢出处理
};

template <class T>
SeqStack<T>::SeqStack(int sz): top(-1), maxSize(sz)
{
    //建立一个最大尺寸为sz的空栈
    elements = new T[maxSize];      //创建栈的数组空间
    assert(elements != NULL);
};


template <class T>
void SeqStack<T>::overflowProcess ()
{
    //扩充栈的存储空间
    T *newArray = new T[2 * maxSize];
    if (newArray == NULL) {cerr << "存储分配失败！" << endl; exit(1);}
    for (int i = 0; i <= top; i++) newArray[i] = elements[i];
    maxSize = 2 * maxSize;
    delete []elements;
    elements = newArray;
};

template <class T>
void SeqStack<T>::push(const T &x)
{
    if (isFull() == true) overflowProcess();
    elements[++top] = x;
};

template <class T>
bool SeqStack<T>::pop(T &x)
{
    if (isEmpty() == true) return false;
    x = elements[top--];
    return true;
};

template <class T>
bool SeqStack<T>::getTop(T &x) const
{
    if (isEmpty() == true) return false;
    x = elements[top];
    return true;
};

template <class Y>
ostream &operator << (ostream &os, SeqStack<Y> &s)
{
    os << "top = " << s.top << endl;        //输出栈顶位置
    for (int i = 0; i <= s.top; i++)
        os << i << ":" << s.elements[i] << endl;
    return os;
};

#endif  //STACK_H