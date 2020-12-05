#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class E>
struct BSTNode
{
    E data;                                                             //二叉树结点类
    BSTNode<E> *child[2];                                               //左子女，右子女
    BSTNode() {child[0] = NULL; child[1] = NULL;}                       //构造函数
    BSTNode(const E &d, BSTNode<E> *L = NULL, BSTNode<E> *R = NULL)
            : data(d) {child[0] = L; child[1] = R;}                     //带数据的构造函数
    void setData(E &d) {data = d;}                                      //修改
    E &getData() {return data;}                                         //提取
};

//二叉搜索树类
//E为存储类型，K为关键码
template <class E, typename K>
class BST
{
    private:
        BSTNode<E> *root;                                            //二叉搜索树根指针
        BSTNode<E> *search(const K &x);                              //循环搜索
        // BSTNode<E> *copy(const BSTNode<E> *ptr);                  //循环复制
        void makeEmpty(BSTNode<E> *&ptr);                            //递归置空
        void printTree(BSTNode<E> *ptr);                             //递归打印（中序遍历）
        bool remove(const K &x, BSTNode<E> *&ptr);                   //递归删除
        bool insert(const E &x, BSTNode<E> *&ptr);                   //循环插入

    public:
        BST(): root(NULL){}                                          //构造函数
        ~BST(){makeEmpty(root);}                                     //析构函数
        bool search(const K &x) const                                //循环搜索
        {return search(x, root) != NULL ? true : false;}
        bool insert(const E &x){return insert(x, root);}             //循环插入
        bool remove(const K &x) {return remove(x, root);}            //递归删除
        E Min() const;                                               //循环求最小
        E Max() const;                                               //循环求最大
};

//递归置空
template <class E, typename K>
void BST<E, K>::makeEmpty(BSTNode<E> *&ptr)
{
    if (ptr != NULL)
    {
        makeEmpty(ptr->child[0]);                                 //递归删除左子树
        makeEmpty(ptr->child[1]);                                 //递归删除右子树
        delete ptr;
    }
}

//循环搜索
template <class E, typename K>
BSTNode<E> *BST<E, K>::search(const K &x)
{
    BSTNode<E> *current = root;
    while (current != NULL)
    {
        if (x == current->data) break;                          //搜索成功
        current = current->child[x > current->data];            //值小，在左子树搜索;值大，在右子树搜索
    } return current;
}

//递归插入
template <class E, typename K>
bool BST<E, K>::insert(const E &x, BSTNode<E> *&ptr)
{
    if (ptr == NULL)                                                    //根为空
    {ptr = new BSTNode<E>(x); if (ptr == NULL) {cerr << "Out of space!" << endl; exit(0);} return true;}
    else if (x < ptr->data) return insert(x, ptr->child[0]);            //值小，在左子树搜索；
    else if (x > ptr->data) return insert(x, ptr->child[1]);            //值大，在右子树搜索
    return false;                                                       //x已在树中，不再插入
}

//递归删除
template <class E, typename K>
bool BST<E, K>::remove(const K &x, BSTNode<E> *& ptr)
{
    BSTNode<E> *temp = NULL;
    if (ptr != NULL)
    {
        if (x < ptr->data) remove(x, ptr->child[0]);                        //在左子树中执行删除
        else if (x > ptr->data) remove(x, ptr->child[1]);                   //在右子树中执行删除
        else if (ptr->child[0] != NULL && ptr->child[1] != NULL)            //结点有两个结点
            {
                temp = ptr->child[1];                                       //到右子树搜寻中序下第一个结点
                while (temp->child[0] != NULL) temp = temp->child[0];       //用该结点数据代替删除结点的数据
                ptr->data = temp->data; remove(ptr->data, ptr->child[1]);
            }
        else                                                                //结点只有一个子女
        {
            temp = ptr; ptr = ptr->child[0] == NULL ? ptr->child[1] : ptr->child[0];
            delete temp; return true;
        }
    } return false;
}

//循环找最大元素
template <class E, typename K>
E BST<E, K>::Max() const
{
    if (root == NULL) return 0;                                             //树为空
    BSTNode<E> *current = root; int p = 1;
    while (p = current->child[1] != NULL, current->child[p] != NULL)        //右子女不空
        current = current->child[p];
}

//循环找最小元素
template <class E, typename K>
E BST<E, K>::Min() const
{
    if (root == NULL) return 0;                                             //树为空
    BSTNode<E> *current = root; int p = 0;
    while (p = current->child[0] != NULL, current->child[0] != NULL)        //右子女不空
        current = current->child[p];
}

//递归打印（中序遍历）
template <class E, typename K>
void BST<E, K>::printTree(BSTNode<E> *ptr)
{
    if (ptr != NULL)
    {
        printTree(ptr->child[0]);
        cout << ptr->data << endl;
        printTree(ptr->child[1]);
    }
}

#endif //BINARYSEARCHTREE_H