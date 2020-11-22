#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdlib.h>
template <class E>
struct BSTNode
{
    E data;                                 //二叉树结点类
    BSTNode<E> *child[2];                   //左子女，右子女
    BSTNode() {child[0] = NULL; child[1] = NULL;}           //构造函数
    BSTNode(const E &d, BSTNode<E> *L = NULL, BSTNode<E> *R = NULL)
            : data(d) {child[0] = L; child[1] = R;}                     //带数据的构造函数
    ~BSTNode<E> {}                                                      //析构函数
    void setData(E &d) {data = d;}                                      //修改
    E &getData() {return data;}                                         //提取
};

template <class E>
class BSTNode
{
    private:
        BSTNode<E> *root;                                                       //二叉搜索树根指针
        template <typename K>
        BSTNode<E> *search(const K &x, BSTNode<E> *ptr);                                    //递归搜索
        BSTNode<E> *copy(const BSTNode<E> *ptr);                                //递归复制
        BSTNode<E> *Min(BSTNode<E> *ptr) const;                                 //递归求最小
        BSTNode<E> *Max(BSTNode<E> *ptr) const;                                 //递归求最大
        bool insert(const E& element, BSTNode<E> *&ptr);                        //递归插入
        bool remove(BSTNode<E> *&ptr);                                          //递归删除
        void makeEmpty(BSTNode<E> *&ptr);                                       //递归置空
        void printTree(BSTNode<E> *ptr);                                        //递归打印

    public:
        BST(): root(NULL)                                                       //构造函数
        ~BST(){};                                                               //析构函数
        bool search(const E )
}




#endif //BINARYSEARCHTREE_H