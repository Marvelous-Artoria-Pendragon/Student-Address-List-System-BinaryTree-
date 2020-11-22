/*链式队列*/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "LinkedList.h"

//链式队列类
template <class T>
class LinkedQueue
{
    public:
        LinkedQueue(): rear(NULL){};                                                 //构造函数，建立空队列
        ~LinkedQueue() {makeEmpty();}                                                //析构函数
        bool EnQueue(const T &x);                                                    //将x加入队列中
        bool DeQueue(T &x);                                                          //取出队头元素，x返回其值
        bool getFront(T &x) const;                                                   //查看队头元素的值
        int getSize() const;                                                         //求队列元素个数
        void makeEmpty();                                                            //置空队列
        bool isEmpty() const {return rear == NULL ? true : false;}                   //判断队列是否为空
        template<class Y>
        friend ostream & operator << (ostream &os, LinkedQueue<Y> &Q);               //重载输出流
    protected:
        LinkNode<T> *rear;                                                           //队尾指针
};

//置空队列，释放链表中所有的结点
template <class T>
void LinkedQueue<T>::makeEmpty()
{
    if (rear == NULL) return; LinkNode<T> *del = NULL;
    while (rear->link != rear)                           //逐个删除队列中的结点
    {del = rear->link; rear->link = del->link; delete del;}
    delete rear;
}

//将新元素x插入队列的队尾(链式队列的链尾)
template <class T>
bool LinkedQueue<T>::EnQueue(const T &x)
{
    if (rear == NULL)
    {
        rear = new LinkNode<T>(x);          //空队列时，新结点成为队列的第一个结点，既是队头也是队尾
        if (rear == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        rear->link = rear;                  //将链表头尾相连
    }
    else
    {
        LinkNode<T> *newNode = new LinkNode<T>(x);      //非空队列时，在链尾追加新的结点，并更新队尾指针
        if (newNode == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        newNode->link = rear->link;                     //新结点的link为队头
        rear->link = newNode;                           //将新结点链上队尾
        rear = newNode;                                 //将rear指向新结点
    } return true;
}

//若队列不为空，将队头结点从链表中删去，函数返回true，否则返回fasle
template <class T>
bool LinkedQueue<T>::DeQueue(T &x)
{
    if (isEmpty()) return false;                        //队空
    LinkNode<T> *top = rear->link; x = top->data;
    rear->link = top->link;
    if (top == rear) rear = NULL;                       //队列只剩下一个元素，删除该结点后，rear指针置空
    delete top; return true;                            //队头修改，释放原队头结点
}

//若队列不为空，则函数返回队头元素的值及true；若为空，返回false
template <class T>
bool LinkedQueue<T>::getFront(T &x) const
{
    if (isEmpty()) return false;                        //队空
    x = rear->link->data; return true;                  //取出队头元素中的数据值
}

//求队列中元素个数
template <class T>
int LinkedQueue<T>::getSize() const
{
    LinkNode<T> *p = rear->link; int k = 0;
    while (p->link != rear->link) {p = p->link; k++;} return k;
}

//重载输出流，输出整个队列元素
template <class T>
ostream &operator << (ostream &os, LinkedQueue<T> &Q)
{
    os << "队列中的元素有" << Q.getSize() << endl;
    LinkNode<T> *p = Q.rear; int i = 0;
    while (p->link != Q.rear->link)
    {
        os << ++i << ":" << p->data << endl;
        p = p->link;
    } return os;
}
#endif //QUEUE_H