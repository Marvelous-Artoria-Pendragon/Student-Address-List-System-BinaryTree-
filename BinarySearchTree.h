#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdlib.h>
template <class E>
struct BSTNode
{
    E data;                                 //�����������
    BSTNode<E> *child[2];                   //����Ů������Ů
    BSTNode() {child[0] = NULL; child[1] = NULL;}           //���캯��
    BSTNode(const E &d, BSTNode<E> *L = NULL, BSTNode<E> *R = NULL)
            : data(d) {child[0] = L; child[1] = R;}                     //�����ݵĹ��캯��
    ~BSTNode<E> {}                                                      //��������
    void setData(E &d) {data = d;}                                      //�޸�
    E &getData() {return data;}                                         //��ȡ
};

template <class E>
class BSTNode
{
    private:
        BSTNode<E> *root;                                                       //������������ָ��
        template <typename K>
        BSTNode<E> *search(const K &x, BSTNode<E> *ptr);                                    //�ݹ�����
        BSTNode<E> *copy(const BSTNode<E> *ptr);                                //�ݹ鸴��
        BSTNode<E> *Min(BSTNode<E> *ptr) const;                                 //�ݹ�����С
        BSTNode<E> *Max(BSTNode<E> *ptr) const;                                 //�ݹ������
        bool insert(const E& element, BSTNode<E> *&ptr);                        //�ݹ����
        bool remove(BSTNode<E> *&ptr);                                          //�ݹ�ɾ��
        void makeEmpty(BSTNode<E> *&ptr);                                       //�ݹ��ÿ�
        void printTree(BSTNode<E> *ptr);                                        //�ݹ��ӡ

    public:
        BST(): root(NULL)                                                       //���캯��
        ~BST(){};                                                               //��������
        bool search(const E )
}




#endif //BINARYSEARCHTREE_H