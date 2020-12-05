/*����������*/
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
struct BinTreeNode                                   //��������������
{
    T data;                                          //������
    BinTreeNode<T> *child[2];                        //����Ů������Ů����
    BinTreeNode() {child[0] = NULL; child[1] = NULL;}
    BinTreeNode(const T &x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
        {data = x; child[0] = l; child[1] = r;}
};

//��ȫ������(��ʽ�ṹ)
template <class T>
class CompleteBinaryTree
{
    protected:
        unsigned size;                                                                          //�������Ľ����
        const unsigned DATA_SIZE = sizeof(T);                                                   //������Ĵ�С
        BinTreeNode<T> *root;                                                                   //�������ĸ�ָ��
        BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current) const;         //���ظ��ڵ�
        BinTreeNode<T> *Parent(unsigned n) const;                                               //Ѱ����ȫ���������Ϊn�Ľ��ĸ����
        BinTreeNode<T> *copy(BinTreeNode<T> *orignode);                                         //����
        template <typename Y>
        BinTreeNode<T> *find(BinTreeNode<T> *&subTree, const Y &x) const;                       //���ҹؼ���Ϊx�Ľ�㣬���ظý��
        void destroy(BinTreeNode<T> *&subTree);                                                 //ɾ��������
        void preOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current));         //ǰ�����
        void inOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current));          //�������
        void postOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *current));        //�������
        void CreateBinTree(istream &in, BinTreeNode<T> *&subTree, unsigned n);                  //��α����ǵݹ齨��
        bool remove(BinTreeNode<T> *current);                                                   //�Ƴ�current���
    public:
        CompleteBinaryTree(): root(NULL), size(0){};                      //���캯��
        CompleteBinaryTree(CompleteBinaryTree<T> &s) {root = copy(s.root); size = s.Size();}    //�������캯��
        ~CompleteBinaryTree() {destroy(root);}                                                  //��������
        BinTreeNode<T> *Parent(BinTreeNode<T> *current)                                         //���ظ��ڵ�
            {return (root == NULL || root == current) ? NULL : Parent(root, current);}
        BinTreeNode<T> *LeftChild(BinTreeNode<T> *current)                                      //��������Ů
            {return (current != NULL) ? current->child[0] : NULL;}
        BinTreeNode<T> *RightChild(BinTreeNode<T> *current)                                     //��������Ů
            {return (current != NULL) ? current->child[1] : NULL;}
        BinTreeNode<T> *getRoot() const{return root;}                                           //���ظ����
        template <typename Y>
        BinTreeNode<T> *find(const Y &x) {return find(root, x);}                                //Ѱ�ҹؼ���Ϊx�Ľ�㣬�������ظý���������
        unsigned Height(BinTreeNode<T> *current) const;                                         //����currentΪ���������߶�
        unsigned Height() const{return ceil(log2(size + 1));};                                  //�������ĸ߶�
        unsigned Size() const {return size;}                                                    //���ؽ����
        bool isEmpty() const {return (root == NULL ? true : false);}                            //�ж϶������շ�
        void preOrder(void (*visit)(BinTreeNode<T> *current)) {preOrder(root, visit);}          //ǰ�����
        void inOrder(void (*visit)(BinTreeNode<T> *current)) {inOrder(root, visit);}            //�������
        void postOrder(void (*visit)(BinTreeNode<T> *current)) {postOrder(root, visit);}        //�������
        void leverOrder(void (*visit)(BinTreeNode<T> *current));                                //��α���
        void CreateBinTree(istream &in, unsigned n) {CreateBinTree(in, root, n);}               //������ȫ������,nΪ���������
        void insert(const T &item);                                                             //��item�����������
        template <typename Y>
        bool remove(const Y &x){return remove(find(root, x));}                                  //�Ƴ�ֵΪx�Ľ��
        bool save(const char *path) const;                                                      //���������Բ�α�����ʽ����������ļ�
        bool load(const char *path);                                                            //�Ӷ������ļ����������
};

//˽�к�������ָ��subTree��Ϊ�գ���ɾ����ΪsubTree������
template <class T>
void CompleteBinaryTree<T>::destroy(BinTreeNode<T> *&subTree)
{
    if (subTree != NULL)
    {
        destroy(subTree->child[0]);                                //�ݹ�ɾ��subTree��������
        destroy(subTree->child[1]);                                //�ݹ�ɾ��subTree��������
        delete subTree; size--;                                    //�ݹ�ɾ��subTree
    }
}

//˽�к���������subTreeΪ�������ĸ߶�
template <class T>
unsigned CompleteBinaryTree<T>::Height(BinTreeNode<T> *subTree) const
{
    if (subTree == NULL) return 0;
    unsigned i = Height(subTree->child[0]), j = Height(subTree->child[1]);
    return (i < j) ? j + 1 : i + 1;
}

//˽�к������ӽ��subTree��ʼ���������current�ĸ���㡣���ҵ����򷵻ظ�����ַ�����򷵻�NULL
template <class T>
BinTreeNode<T> *CompleteBinaryTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current) const
{
    if (subTree == NULL) return NULL;
    if (subTree->child[0] == current || subTree->child[1] == current) return subTree;    //�ҵ������ظ����subTree
    BinTreeNode<T> *p = Parent(subTree->child[0], current);
    return (p != NULL) ? p : Parent(subTree->child[1], current);
}

//˽�к�����������ȫ���������Ϊn�ĵĸ����
template <class T>
BinTreeNode<T> *CompleteBinaryTree<T>::Parent(unsigned n) const
{
    if (n == 1) return NULL;                                    //������޸����
    unsigned level = ceil(log2(n + 1)) - 1,                     //parent���ڲ�
    p = n >> 1,                                                 //���ڵ���
    first = 1 << (level - 1),                                   //�ò��һ�������
    end = (1 << level) - 1,                                     //�ò����һ�������
    middle = (first + end) >> 1,                                //�ò��м���
    i = 1;                                                      //���Ѱ�Ҵ���
    BinTreeNode<T> *current = root;
    while (i++ < level)                                         //�۰�Ѱ��level��
    {
        current = current->child[p > middle];                   //�����С�ڵ����м��ţ����������ҷ�������������
        if (p > middle) first = middle;                         //���µ�һ���ı��
        else end = middle;                                      //�������ı��
        middle = (first + end) >> 1;                         //�м����۰����
    } return current;
}

//˽�к����������������һ��ָ�룬������һ����orignodeΪ���Ķ������ĸ���
template <class T>
BinTreeNode<T> *CompleteBinaryTree<T>::copy(BinTreeNode<T> *orignode)
{
    if (orignode == NULL) return NULL;                                  //��Ϊ�գ����ؿ�ָ��
    BinTreeNode<T> *temp = new BinTreeNode<T>(orignode->data); size++;  //���������
    if (temp == NULL) {cerr << "�洢�������" << endl; exit(1);} 
    temp->child[0] = copy(orignode->child[0]);                          //��������Ů
    temp->child[1] = copy(orignode->child[1]);                          //��������Ů
    return temp;
}

//˽�к�������subTreeΪ���£�Ѱ�ҹؼ���Ϊx�Ľ�㣬�������ظý���ַ(�Ҳ�������NULL)
//cmpΪ�ȽϺ���(��������)���������뵱ǰ����data(T)
template<class T>
template <typename Y>
BinTreeNode<T> *CompleteBinaryTree<T>::find(BinTreeNode<T> *&subTree, const Y &x) const
{
    if (subTree == NULL) return NULL;                                   //����ս�㣬����NULL
    if (subTree->data == x) return subTree;                             //�ҵ�item�����ظý���ַ
    BinTreeNode<T> *temp = find(subTree->child[0], x);
    return temp != NULL ? temp : find(subTree->child[1], x);          //�ݹ���������Ů��Ѱ��
}

//��α�������
//inΪ��������subTreeΪ��������㣬nΪ�½������
template <class T>
void CompleteBinaryTree<T>::CreateBinTree(istream &in, BinTreeNode<T> *&subTree, unsigned n)
{
    destroy(root);                                                          //�ݻ�ԭ������
    LinkedQueue<BinTreeNode<T> *> Q; size = n;                              //���ý����
    subTree = new BinTreeNode<T>; if (subTree == NULL) {cerr << "�洢�������" << endl; exit(1);}    //�½������
    cout << "��1��ѧ����Ϣ��\n"; in >> subTree->data;
    BinTreeNode<T> *temp = subTree, *newNode = NULL; unsigned cnt = 1;      //���½�������
    Q.EnQueue(temp);                                                        //������Ƚ���
    while (cnt < size)
    {
        if (++cnt & 1) Q.DeQueue(temp);                                     //�½�����Ů���˶�
        else Q.getFront(temp);
        newNode = new BinTreeNode<T>; if (newNode == NULL) {cerr << "�洢�������" << endl; exit(1);}
        cout << "��" << cnt << "��ѧ����Ϣ\n";
        in >> newNode->data; Q.EnQueue(newNode);                            //������Ů����
        temp->child[(cnt & 1)] = newNode;                                   //�½������
    }
}

//�ݹ�ǰ�����
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

//�ݹ��������
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

//�ݹ�������
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

//���ö���ʵ�ֲ�������
template <class T>
void CompleteBinaryTree<T>::leverOrder(void (*visit)(BinTreeNode<T> *currentNode))
{
    LinkedQueue<BinTreeNode<T> * > Q; BinTreeNode<T> *current = root;
    Q.EnQueue(current);
    while (!Q.isEmpty())                                //���в�Ϊ��
    {
        Q.DeQueue(current); visit(current);             //�˳�һ����㣬����
        if (current->child[0] != NULL) Q.EnQueue(current->child[0]);      //����Ů����
        if (current->child[1] != NULL) Q.EnQueue(current->child[1]);      //����Ů����
    }
}

//�Ƴ����Ϊn�Ľ᣺�����һ������ֵ�滻�ý�㣬Ȼ��ɾ�������������һ�����
template <class T>
bool CompleteBinaryTree<T>::remove(BinTreeNode<T> *current)
{
    if (current == NULL) return false;                                             //ɾ���Ľ��Ϊ��
    if (size == 1) {delete root; root = NULL; size = 0; return true;}              //ֻ��һ����㣬ɾ�����Ϊ���ڵ�
    BinTreeNode<T> *parent = Parent(size); size--;
    BinTreeNode<T> *&temp = (parent->child[1] != NULL) ? parent->child[1] : parent->child[0];
    current->data = temp->data; delete temp; temp = NULL;                          //��Ů�滻�ý��(��������)
    return true;
}

//��ֵΪitem�Ľ������������(���һ�����)
template <class T>
void CompleteBinaryTree<T>::insert(const T &item)
{
    BinTreeNode<T> *parent = Parent(++size), *temp = new BinTreeNode<T>(item);
    if (temp == NULL) {cerr << "�洢�������" << endl; exit(1);}
    if (root == NULL) {root = temp; return;}
    parent->child[(size & 1)] = temp;
}

//���������Բ�α�����ʽ����������ļ�
template <class T>
bool CompleteBinaryTree<T>::save(const char *path) const
{
    ofstream outfile(path, ios::out | ios::binary);
    char version[] = "0xA0B0C0";                                           //��־�ļ��Ƿ���Ч
    if (root == NULL || !outfile) {outfile.close(); return false;}         //��Ϊ�ջ��ļ���ʧ��
    LinkedQueue<BinTreeNode<T> * > Q; BinTreeNode<T> *current = root;
    outfile.write(version, 8);                                             //д���ļ���ʶ��
    Q.EnQueue(current);
    while (!Q.isEmpty())                                                   //���в�Ϊ��
    {
        Q.DeQueue(current); outfile.write((char *)&current->data, DATA_SIZE);             //�˳�һ����㣬д���ļ�
        if (current->child[0] != NULL) Q.EnQueue(current->child[0]);      //����Ů����
        if (current->child[1] != NULL) Q.EnQueue(current->child[1]);      //����Ů����
    } outfile.close(); return true;
}

//�Ӷ������ļ��ж��������
template <class T>
bool CompleteBinaryTree<T>::load(const char *path)
{
    ifstream infile(path, ios::in | ios::binary); char version[9];
    if (!infile || (infile.read(version, 8), strcmp(version, "0xA0B0C0") != 0)) 
        {infile.close(); return false;}                                     //���ļ�ʧ��
    destroy(root);                                                          //�����ԭ������
    LinkedQueue<BinTreeNode<T> *> Q; T item;                                //��ʱ�ṹ��
    if (infile.read((char *) &item, DATA_SIZE))
    {
        root = new BinTreeNode<T>(item); size++;
        if (root == NULL) {cerr << "�洢�������" << endl; exit(1);}       //�½������
    } else return false;                                                    //��ȡû�����ݣ���ȡʧ��
    BinTreeNode<T> *temp = root, *newNode = NULL;                           //��ǰ����Ľ��
    Q.EnQueue(temp);                                                        //������Ƚ���
    while (infile.read((char *) &item, DATA_SIZE))
    {
        if (++size & 1) Q.DeQueue(temp);                                    //�½�����Ů���˶�
        else Q.getFront(temp);                                              //�½�����Ů����ǰ��㲻�˶�
        newNode = new BinTreeNode<T>(item); if (temp == NULL) {cerr << "�洢�������" << endl; exit(1);}
        Q.EnQueue(newNode);                                                 //������Ů����
        temp->child[(size & 1)] = newNode;                                  //�½������
    } infile.close(); return true;
}
#endif //COMPLETEBINARYTREE_H