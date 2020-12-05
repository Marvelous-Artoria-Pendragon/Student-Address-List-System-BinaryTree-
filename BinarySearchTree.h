#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class E>
struct BSTNode
{
    E data;                                                             //�����������
    BSTNode<E> *child[2];                                               //����Ů������Ů
    BSTNode() {child[0] = NULL; child[1] = NULL;}                       //���캯��
    BSTNode(const E &d, BSTNode<E> *L = NULL, BSTNode<E> *R = NULL)
            : data(d) {child[0] = L; child[1] = R;}                     //�����ݵĹ��캯��
    void setData(E &d) {data = d;}                                      //�޸�
    E &getData() {return data;}                                         //��ȡ
};

//������������
//EΪ�洢���ͣ�KΪ�ؼ���
template <class E, typename K>
class BST
{
    private:
        BSTNode<E> *root;                                            //������������ָ��
        BSTNode<E> *search(const K &x);                              //ѭ������
        // BSTNode<E> *copy(const BSTNode<E> *ptr);                  //ѭ������
        void makeEmpty(BSTNode<E> *&ptr);                            //�ݹ��ÿ�
        void printTree(BSTNode<E> *ptr);                             //�ݹ��ӡ�����������
        bool remove(const K &x, BSTNode<E> *&ptr);                   //�ݹ�ɾ��
        bool insert(const E &x, BSTNode<E> *&ptr);                   //ѭ������

    public:
        BST(): root(NULL){}                                          //���캯��
        ~BST(){makeEmpty(root);}                                     //��������
        bool search(const K &x) const                                //ѭ������
        {return search(x, root) != NULL ? true : false;}
        bool insert(const E &x){return insert(x, root);}             //ѭ������
        bool remove(const K &x) {return remove(x, root);}            //�ݹ�ɾ��
        E Min() const;                                               //ѭ������С
        E Max() const;                                               //ѭ�������
};

//�ݹ��ÿ�
template <class E, typename K>
void BST<E, K>::makeEmpty(BSTNode<E> *&ptr)
{
    if (ptr != NULL)
    {
        makeEmpty(ptr->child[0]);                                 //�ݹ�ɾ��������
        makeEmpty(ptr->child[1]);                                 //�ݹ�ɾ��������
        delete ptr;
    }
}

//ѭ������
template <class E, typename K>
BSTNode<E> *BST<E, K>::search(const K &x)
{
    BSTNode<E> *current = root;
    while (current != NULL)
    {
        if (x == current->data) break;                          //�����ɹ�
        current = current->child[x > current->data];            //ֵС��������������;ֵ��������������
    } return current;
}

//�ݹ����
template <class E, typename K>
bool BST<E, K>::insert(const E &x, BSTNode<E> *&ptr)
{
    if (ptr == NULL)                                                    //��Ϊ��
    {ptr = new BSTNode<E>(x); if (ptr == NULL) {cerr << "Out of space!" << endl; exit(0);} return true;}
    else if (x < ptr->data) return insert(x, ptr->child[0]);            //ֵС����������������
    else if (x > ptr->data) return insert(x, ptr->child[1]);            //ֵ��������������
    return false;                                                       //x�������У����ٲ���
}

//�ݹ�ɾ��
template <class E, typename K>
bool BST<E, K>::remove(const K &x, BSTNode<E> *& ptr)
{
    BSTNode<E> *temp = NULL;
    if (ptr != NULL)
    {
        if (x < ptr->data) remove(x, ptr->child[0]);                        //����������ִ��ɾ��
        else if (x > ptr->data) remove(x, ptr->child[1]);                   //����������ִ��ɾ��
        else if (ptr->child[0] != NULL && ptr->child[1] != NULL)            //������������
            {
                temp = ptr->child[1];                                       //����������Ѱ�����µ�һ�����
                while (temp->child[0] != NULL) temp = temp->child[0];       //�øý�����ݴ���ɾ����������
                ptr->data = temp->data; remove(ptr->data, ptr->child[1]);
            }
        else                                                                //���ֻ��һ����Ů
        {
            temp = ptr; ptr = ptr->child[0] == NULL ? ptr->child[1] : ptr->child[0];
            delete temp; return true;
        }
    } return false;
}

//ѭ�������Ԫ��
template <class E, typename K>
E BST<E, K>::Max() const
{
    if (root == NULL) return 0;                                             //��Ϊ��
    BSTNode<E> *current = root; int p = 1;
    while (p = current->child[1] != NULL, current->child[p] != NULL)        //����Ů����
        current = current->child[p];
}

//ѭ������СԪ��
template <class E, typename K>
E BST<E, K>::Min() const
{
    if (root == NULL) return 0;                                             //��Ϊ��
    BSTNode<E> *current = root; int p = 0;
    while (p = current->child[0] != NULL, current->child[0] != NULL)        //����Ů����
        current = current->child[p];
}

//�ݹ��ӡ�����������
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