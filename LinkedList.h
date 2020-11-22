#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

//带附加头结点的单链表的类定义
template <class T>
struct LinkNode
{
    T data;                                             //数据域
    LinkNode<T> *link;                                  //链指针域
    LinkNode(LinkNode<T> *ptr = NULL) {link = ptr;}     //仅初始化指针成员的构造函数
    LinkNode(const T &item, LinkNode<T> *ptr = NULL)    //初始化数据域指针成员的构造函数
    {data = item; link = ptr;}
};

template <class T>
class LinkedList          //带表头结点的非循环单链表
{
    public:
        LinkedList(LinkNode<T> *other = new LinkNode<T>) {first = other; length = 0;}  //构造函数,默认带空表头
        LinkedList(LinkedList<T> &L);                           //复制构造函数
        ~LinkedList() {makeEmpty();}                            //析构函数
        void makeEmpty();                                       //将链表置换为空表
        int Length() const {return length;}                     //返回当前链表元素个数(不含空结点)
        LinkNode<T> *getHead() const {return first;}            //返回附加头结点地址
        LinkNode<T> *search(T x) const;                         //搜索含数据x的元素
        LinkNode<T> *locate(int i) const;                       //搜索第i个元素的地址
        bool getData(int i, T &x) const;                        //取出第i个元素的值
        void setData(int i, T &x);                              //用x修改第i个元素的值
        bool insert(int i, T &x);                               //在第i个元素后插入x
        void append(T &x);                                      //在链表末尾添加新结点
        bool remove(int i, T &x);                               //删除第i个元素，x返回该元素的值
        bool isEmpty() const                                    //判断链表是否为空
        {return length == 0 ? true : false;}
        bool isFull()const {return false;}                      //判断链表是否为满
        template <class Y>
        friend ostream &operator << (ostream &out, LinkedList<Y> &L);

        void inputFront(T endTag);                              //前插法建立单链表
        void inputRear(T endTag);                               //后插法建立单链表
        LinkedList<T> &operator = (LinkedList<T> &L);           //重载函数：赋值
    protected:
        LinkNode<T> *first;                                     //链表的头指针
        int length;                                             //链表元素个数
};

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &L)
{
    //复制构造函数
    LinkNode<T> *srcptr = L.getHead()->link;              //被赋值表的附加头结点的下一个结点
    LinkNode<T> *destptr = first = new LinkNode<T>;
    while (srcptr != NULL)                                //逐个结点复制
    {
        LinkNode<T> *newNode = new LinkNode<T>(srcptr->data);
        if (newNode == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        destptr->link = newNode;
        destptr = destptr -> link;
        srcptr = srcptr -> link;
        length++;                                         //length计数
    }
};

template <class T>
void LinkedList<T>::makeEmpty()
{
    //将链表置换为空表
    LinkNode<T> *del;
    while (first->link != NULL)             //当链不空时，删去链中所有结点
    {
        del = first->link;                
        first->link = del->link;            //保存被删结点，从前往后摘下结点
        delete del;                         //删除(仅保留一个表头结点)
    }
    length = 0;
};


template <class T>
LinkNode<T> *LinkedList<T>::search(T x) const
{
    //在表中搜索含数据x的结点，搜索成功时函数返回该结点的地址；否则返回NULL值
    LinkNode<T> *current = first->link;
    while (current != NULL)                         //循链找含x结点
        if (current -> data == x) break;            //找到，跳出循环
        else current = current -> link;             //未找到，继续寻找下一个结点
    return current;
};

template <class T>
LinkNode<T> *LinkedList<T>::locate(int i) const
{
    //定位函数。返回表中第i个元素的地址。若i<0或i超出表中结点个数，则返回NULL(0为表头结点)
    if (i < 0 || i > Length) return NULL;                           //i不合理
    LinkNode<T> *current = first; int k = 0;
    while (current != NULL && k++ < i) current = current -> link;   //循链找第i个结点
    return current;                                                 //返回第i个结点地址，若返回NULL，表示i值太大
};

template <class T>
bool LinkedList<T>::getData(int i, T &x) const
{
    //取出链表中第i个元素的值
    LinkNode<T> *current = locate(i);
    if (current == NULL) return false;               //i值不合理
    x = current->data; return true;                  //搜索成功，通过引用返回，函数返回true
};

template <class T>
void LinkedList<T>::setData(int i, T &x)
{
    //给链表中第i个元素赋值x
    LinkNode<T> *current = locate(i);
    if (current == NULL) return;                    //i值不合理
    current->data = x;
}

template <class T>
bool LinkedList<T>::insert(int i, T &x)
{
    //将新元素x插入在链表中第i个结点之后
    LinkNode<T> *current = locate(i);
    if (current == NULL) return false;              //插入不成功
    LinkNode<T> *newNode = new LinkNode<T>(x);
    if (newNode == NULL) {cerr << "存储分配错误！" <<endl; exit(1);}
    newNode->link = current->link;              //链接在current之后
    current->link = newNode;
    return true;                                    //插入成功
}

template <class T>
bool LinkedList<T>::remove(int i, T &x)
{
    //将链表中第i个元素删去，通过引用型参数x返回该元素的值
    LinkNode<T> *current = locate(i - 1);           //寻找删除结点的前一个结点
    if (current == NULL) return false;              //删除不成功
    LinkNode<T> *del = current->link;               //重新拉链，将被删结点从链中摘下
    current->link = del->link;
    x = del->data; delete del;                      //取出被删结点中的数据值
    length--; return true;                          //计数减一
}

template <class T>
ostream &operator << (ostream &out, LinkedList<T> L)
{
    //单链表的输出函数：将单链表中所有数据按逻辑顺序输出到屏幕上
    LinkNode<T> *current = L.first->link;           //跳过空表头
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->link;
    } return out;
};

template <class T>
LinkedList<T> &LinkedList<T>::operator = (LinkedList<T> &L)
{
    //重载函数：赋值操作，形式如A = B，其中A是调用此操作的List对象，B是与参数表中的引用型参数L结合的实参
    LinkNode<T> *srcptr = L.getHead()->link;              //被复制表的附加头结点的下一个结点
    LinkNode<T> *destptr = first = new LinkNode<T>;
    while (srcptr != NULL)                                //逐个结点复制
    {
        LinkNode<T> *newNode = new LinkNode<T>(srcptr->data);
        if (newNode == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        destptr->link = newNode;
        destptr = destptr -> link;                       //对赋值对象下一个结点操作
        srcptr = srcptr -> link;                         //跳到源链表的下一个结点
        length++;
    } return *this;                                      //返回操作对象地址
}

template <class T>
void LinkedList<T>::inputFront(T endTag)
{
    //endTag 是约定的输入序列结束的标志。如果输入序列是正整数，endTag可以是0或负数
    LinkNode<T> *newNode; T val;
    makeEmpty();
    cin >> val;
    while (val != endTag)
    {
        newNode = new LinkNode<T>(val);              //创建新结点
        if (newNode == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        newNode->link = first->link;
        first -> link = newNode;                    //插入到表前端
        length++;
        cin >> val;
    }
};

template <class T>
void LinkedList<T>::inputRear(T endTag)
{
    LinkNode<T> *newNode, *last; T val;
    makeEmpty();
    cin >> val; last = first;
    while (val != endTag)               //last指向表尾
    {
        newNode = new LinkNode<T>(val);
        if (newNode == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        last->link = newNode; last = newNode;             //插入到表末端
        length++;
        cin >> val;
    }
};

#endif //LINKEDLIST_H