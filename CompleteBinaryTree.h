/*二叉链表树*/
#ifndef COMPLETEBINARYTREE_H
#define COMPLETEBINARYTREE_H
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
using namespace std;

template <class T>
struct BinTreeNode                                   //二叉树的链表结点
{
    T data;                                          //数据域
    BinTreeNode<T> *child[2];                        //左子女，右子女链域
    BinTreeNode() {child[0] = NULL; child[1] = NULL;}
    BinTreeNode(const T &x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
        {data = x; child[0] = l; child[1] = r;}
};

//完全二叉树(链式结构)
template <class T>
class CompleteBinaryTree
{
    protected:
        unsigned size;                                                                          //二叉树的结点数
        const unsigned DATA_SIZE = sizeof(T);                                                   //数据域的大小
        BinTreeNode<T> *root;                                                                   //二叉树的根指针
        BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current) const;         //返回父节点
        BinTreeNode<T> *Parent(unsigned n) const;                                               //寻找完全二叉树编号为n的结点的父结点
        BinTreeNode<T> *copy(BinTreeNode<T> *orignode);                                         //复制
        template <typename Y>
        BinTreeNode<T> *find(BinTreeNode<T> *&subTree, const Y &x) const;                           //根据cmp函数查找对应的结点，返回该结点
        void destroy(BinTreeNode<T> *&subTree);                                                 //删除整棵树
        void preOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current));         //前序遍历
        void inOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current));          //中序遍历
        void postOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current));        //后序遍历
        void CreateBinTree(istream &in, BinTreeNode<T> *&subTree, unsigned n);                  //层次遍历非递归建树
        bool remove(BinTreeNode<T> *current);                                                   //移除current结点
    public:
        CompleteBinaryTree(): root(NULL), size(0){};                      //构造函数
        CompleteBinaryTree(CompleteBinaryTree<T> &s) {root = copy(s.root); size = s.Size();}    //拷贝构造函数
        ~CompleteBinaryTree() {destroy(root);}                                                  //析构函数
        BinTreeNode<T> *Parent(BinTreeNode<T> *current)                                         //返回父节点
            {return (root == NULL || root == current) ? NULL : Parent(root, current);}
        BinTreeNode<T> *LeftChild(BinTreeNode<T> *current)                                      //返回左子女
            {return (current != NULL) ? current->child[0] : NULL;}
        BinTreeNode<T> *RightChild(BinTreeNode<T> *current)                                     //返回右子女
            {return (current != NULL) ? current->child[1] : NULL;}
        BinTreeNode<T> *getRoot() const{return root;}                                           //返回根结点
        template <typename Y>
        BinTreeNode<T> *find(const Y &x) {return find(root, x);}                                //根据cmp函数寻找结点，函数返回该结点地址
        unsigned Height(BinTreeNode<T> *current) const;                                         //返回current为根的子树高度
        unsigned Height() const{return ceil(log2(size + 1));};                                  //返回树的高度
        unsigned Size() const {return size;}                                                    //返回结点数
        bool isEmpty() const {return (root == NULL ? true : false);}                            //判断二叉树空否
        void preOrder(void (*visit)(BinTreeNode<T> *current)) {preOrder(root, visit);}          //前序遍历
        void inOrder(void (*visit)(BinTreeNode<T> *current)) {inOrder(root, visit);}            //中序遍历
        void postOrder(void (*visit)(BinTreeNode<T> *current)) {postOrder(root, visit);}        //后序遍历
        void leverOrder(void (*visit)(BinTreeNode<T> *current));                                //层次遍历
        void CreateBinTree(istream &in, unsigned n) {CreateBinTree(in, root, n);}               //创建完全二叉树,n为创建结点数
        void insert(const T &item);                                                             //将item插入二叉树中
        template <typename Y>
        bool remove(const Y &x){return remove(find(root, x));}                                  //移除满足cmp函数的结点
        bool save(const char *path) const;                                                      //将二叉树以层次遍历方式存入二进制文件
        bool load(const char *path);                                                            //从二进制文件导入二叉树
};

//私有函数：若指针subTree不为空，则删除根为subTree的子树
template <class T>
void CompleteBinaryTree<T>::destroy(BinTreeNode<T> *&subTree)
{
    if (subTree != NULL)
    {
        destroy(subTree->child[0]);                                //递归删除subTree的左子树
        destroy(subTree->child[1]);                                //递归删除subTree的右子树
        delete subTree; size--;                                    //递归删除subTree
    }
}

//私有函数，返回subTree为根的树的高度
template <class T>
unsigned CompleteBinaryTree<T>::Height(BinTreeNode<T> *subTree) const
{
    if (subTree == NULL) return 0;
    unsigned i = Height(subTree->child[0]), j = Height(subTree->child[1]);
    return (i < j) ? j + 1 : i + 1;
}

//私有函数：从结点subTree开始，搜索结点current的父结点。若找到，则返回父结点地址，否则返回NULL
template <class T>
BinTreeNode<T> *CompleteBinaryTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current) const
{
    if (subTree == NULL) return NULL;
    if (subTree->child[0] == current || subTree->child[1] == current) return subTree;    //找到，返回父结点subTree
    BinTreeNode<T> *p = Parent(subTree->child[0], current);
    return (p != NULL) ? p : Parent(subTree->child[1], current);
}

//私有函数：返回完全二叉树编号为n的的父结点
template <class T>
BinTreeNode<T> *CompleteBinaryTree<T>::Parent(unsigned n) const
{
    if (n == 1) return NULL;                                    //根结点无父结点
    unsigned level = ceil(log2(n + 1)) - 1,                     //parent所在层
    p = n >> 1,                                                 //父节点编号
    first = 1 << (level - 1),                                   //该层第一个结点编号
    end = (1 << level) - 1,                                     //该层最后一个结点编号
    middle = (first + end) >> 1,                                //该层中间编号
    i = 1;                                                      //标记寻找次数
    BinTreeNode<T> *current = root;
    while (i++ < level)                                         //折半寻找level次
    {
        current = current->child[p > middle];                   //结点编号小于等于中间编号，在左子树找否则在右子树找
        if (p > middle) first = middle;                         //更新第一个的编号
        else end = middle;                                      //更新最后的编号
        middle = (first + end) >> 1;                         //中间编号折半更新
    } return current;
}

//私有函数：这个函数返回一个指针，它给出一个以orignode为根的二叉树的副本
template <class T>
BinTreeNode<T> *CompleteBinaryTree<T>::copy(BinTreeNode<T> *orignode)
{
    if (orignode == NULL) return NULL;                                  //根为空，返回空指针
    BinTreeNode<T> *temp = new BinTreeNode<T>(orignode->data); size++;  //创建根结点
    if (temp == NULL) {cerr << "存储分配错误！" << endl; exit(1);} 
    temp->child[0] = copy(orignode->child[0]);                          //复制左子女
    temp->child[1] = copy(orignode->child[1]);                          //复制右子女
    return temp;
}

//私有函数：在subTree为根下，根据cmp函数指示当前结点是否为所找的结点，函数返回该结点地址(找不到返回NULL)
//cmp为比较函数(布尔类型)，函数传入当前结点的data(T)
template<class T>
template <typename Y>
BinTreeNode<T> *CompleteBinaryTree<T>::find(BinTreeNode<T> *&subTree, const Y &x) const
{
    if (subTree == NULL) return NULL;                                   //到达空结点，返回NULL
    if (subTree->data == x) return subTree;                             //根据匹配函数找到item，返回该结点地址
    BinTreeNode<T> *temp = find(subTree->child[0], x);
    return temp != NULL ? temp : find(subTree->child[1], x);          //递归在左右子女中寻找
}

//层次遍历建树
//in为输入流，subTree为建树根结点，n为新建结点数
template <class T>
void CompleteBinaryTree<T>::CreateBinTree(istream &in, BinTreeNode<T> *&subTree, unsigned n)
{
    LinkedQueue<BinTreeNode<T> *> Q; size = n;                              //设置结点数
    destroy(root);                                                          //摧毁原二叉树
    subTree = new BinTreeNode<T>; if (subTree == NULL) {cerr << "存储分配错误！" << endl; exit(1);}    //新建根结点
    cout << "第1个学生信息：\n"; in >> subTree->data;
    BinTreeNode<T> *temp = subTree, *newNode = NULL; unsigned cnt = 1;      //对新建结点计数
    Q.EnQueue(temp);                                                        //根结点先进队
    while (cnt < size)
    {
        if (++cnt & 1) Q.DeQueue(temp);                                     //新建右子女才退队
        else Q.getFront(temp);
        newNode = new BinTreeNode<T>; if (newNode == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        cout << "第" << cnt << "个学生信息\n";
        in >> newNode->data; Q.EnQueue(newNode);                            //左、右子女进队
        temp->child[(cnt & 1)] = newNode;                                   //新结点入树
    }
}

//递归前序遍历
template <class T>
void CompleteBinaryTree<T>::preOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current))
{
    if (subTree != NULL)
    {
        visit(subTree);
        preOrder(subTree->child[0], visit);
        preOrder(subTree->child[1], visit);
    }
}

//递归中序遍历
template <class T>
void CompleteBinaryTree<T>::inOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current))
{
    if (subTree != NULL)
    {
        inOrder(subTree->child[0], visit);
        visit(subTree);
        inOrder(subTree->child[1], visit);
    }
}

//递归后序遍历
template <class T>
void CompleteBinaryTree<T>::postOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current))
{
    if (subTree != NULL)
    {
        postOrder(subTree->child[0], visit);
        postOrder(subTree->child[1], visit);
        visit(subTree);
    }
}

//利用队列实现层次序遍历
template <class T>
void CompleteBinaryTree<T>::leverOrder(void (*visit)(BinTreeNode<T> *currentNode))
{
    LinkedQueue<BinTreeNode<T> * > Q; BinTreeNode<T> *current = root;
    Q.EnQueue(current);
    while (!Q.isEmpty())                                //队列不为空
    {
        Q.DeQueue(current); visit(current);             //退出一个结点，访问
        if (current->child[0] != NULL) Q.EnQueue(current->child[0]);      //左子女进队
        if (current->child[1] != NULL) Q.EnQueue(current->child[1]);      //右子女进队
    }
}

//移除编号为n的结：将最后一个结点的值替换该结点，然后删除二叉树中最后一个结点
template <class T>
bool CompleteBinaryTree<T>::remove(BinTreeNode<T> *current)
{
    if (current == NULL) return false;                                             //删除的结点为空
    if (size == 1) {delete root; root = NULL; size = 0; return true;}              //只有一个结点，删除结点为根节点
    BinTreeNode<T> *parent = Parent(size); size--;
    BinTreeNode<T> *&temp = (parent->child[1] != NULL) ? parent->child[1] : parent->child[0];
    current->data = temp->data; delete temp; temp = NULL;                          //子女替换该结点(右先于左)
    return true;
}

//将值为item的结点插入二叉树中(最后一个结点)
template <class T>
void CompleteBinaryTree<T>::insert(const T &item)
{
    BinTreeNode<T> *parent = Parent(++size), *temp = new BinTreeNode<T>(item);
    if (temp == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
    if (root == NULL) {root = temp; return;}
    parent->child[(size & 1)] = temp;
}

//将二叉树以层次遍历方式存入二进制文件
template <class T>
bool CompleteBinaryTree<T>::save(const char *path) const
{
    ofstream outfile(path, ios::out | ios::binary);
    char version[] = "0xA0B0C0";                                           //标志文件是否有效
    if (root == NULL || !outfile) {outfile.close(); return false;}         //根为空或文件打开失败
    LinkedQueue<BinTreeNode<T> * > Q; BinTreeNode<T> *current = root;
    outfile.write(version, 8);                                             //写入文件标识符
    Q.EnQueue(current);
    while (!Q.isEmpty())                                                   //队列不为空
    {
        Q.DeQueue(current); outfile.write((char *)&current->data, DATA_SIZE);             //退出一个结点，写入文件
        if (current->child[0] != NULL) Q.EnQueue(current->child[0]);      //左子女进队
        if (current->child[1] != NULL) Q.EnQueue(current->child[1]);      //右子女进队
    } outfile.close(); return true;
}

//从二进制文件中读入二叉树
template <class T>
bool CompleteBinaryTree<T>::load(const char *path)
{
    ifstream infile(path, ios::in | ios::binary); char version[9];
    if (!infile || (infile.read(version, 8), strcmp(version, "0xA0B0C0") != 0)) 
        {infile.close(); return false;}                                     //打开文件失败
    destroy(root);                                                          //先清空原二叉树
    LinkedQueue<BinTreeNode<T> *> Q; T item;
    if (infile.read((char *) &item, DATA_SIZE))
    {
        root = new BinTreeNode<T>(item); size++;
        if (root == NULL) {cerr << "存储分配错误！" << endl; exit(1);}       //新建根结点
    } else return false;
    BinTreeNode<T> *temp = root, *newNode = NULL;                           //当前处理的结点
    Q.EnQueue(temp);                                                        //根结点先进队
    while (infile.read((char *) &item, DATA_SIZE))
    {
        if (++size & 1) Q.DeQueue(temp);                                    //新建右子女才退队
        else Q.getFront(temp);                                              //新建左子女，当前结点不退队
        newNode = new BinTreeNode<T>(item); if (temp == NULL) {cerr << "存储分配错误！" << endl; exit(1);}
        Q.EnQueue(newNode);                                                 //左、右子女进队
        temp->child[(size & 1)] = newNode;                                  //新结点入树
    } infile.close(); return true;
}
#endif //COMPLETEBINARYTREE_H