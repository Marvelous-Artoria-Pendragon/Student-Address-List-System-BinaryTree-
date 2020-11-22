/*��ʽ����*/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "LinkedList.h"

//��ʽ������
template <class T>
class LinkedQueue
{
    public:
        LinkedQueue(): rear(NULL){};                                                 //���캯���������ն���
        ~LinkedQueue() {makeEmpty();}                                                //��������
        bool EnQueue(const T &x);                                                    //��x���������
        bool DeQueue(T &x);                                                          //ȡ����ͷԪ�أ�x������ֵ
        bool getFront(T &x) const;                                                   //�鿴��ͷԪ�ص�ֵ
        int getSize() const;                                                         //�����Ԫ�ظ���
        void makeEmpty();                                                            //�ÿն���
        bool isEmpty() const {return rear == NULL ? true : false;}                   //�ж϶����Ƿ�Ϊ��
        template<class Y>
        friend ostream & operator << (ostream &os, LinkedQueue<Y> &Q);               //���������
    protected:
        LinkNode<T> *rear;                                                           //��βָ��
};

//�ÿն��У��ͷ����������еĽ��
template <class T>
void LinkedQueue<T>::makeEmpty()
{
    if (rear == NULL) return; LinkNode<T> *del = NULL;
    while (rear->link != rear)                           //���ɾ�������еĽ��
    {del = rear->link; rear->link = del->link; delete del;}
    delete rear;
}

//����Ԫ��x������еĶ�β(��ʽ���е���β)
template <class T>
bool LinkedQueue<T>::EnQueue(const T &x)
{
    if (rear == NULL)
    {
        rear = new LinkNode<T>(x);          //�ն���ʱ���½���Ϊ���еĵ�һ����㣬���Ƕ�ͷҲ�Ƕ�β
        if (rear == NULL) {cerr << "�洢�������" << endl; exit(1);}
        rear->link = rear;                  //������ͷβ����
    }
    else
    {
        LinkNode<T> *newNode = new LinkNode<T>(x);      //�ǿն���ʱ������β׷���µĽ�㣬�����¶�βָ��
        if (newNode == NULL) {cerr << "�洢�������" << endl; exit(1);}
        newNode->link = rear->link;                     //�½���linkΪ��ͷ
        rear->link = newNode;                           //���½�����϶�β
        rear = newNode;                                 //��rearָ���½��
    } return true;
}

//�����в�Ϊ�գ�����ͷ����������ɾȥ����������true�����򷵻�fasle
template <class T>
bool LinkedQueue<T>::DeQueue(T &x)
{
    if (isEmpty()) return false;                        //�ӿ�
    LinkNode<T> *top = rear->link; x = top->data;
    rear->link = top->link;
    if (top == rear) rear = NULL;                       //����ֻʣ��һ��Ԫ�أ�ɾ���ý���rearָ���ÿ�
    delete top; return true;                            //��ͷ�޸ģ��ͷ�ԭ��ͷ���
}

//�����в�Ϊ�գ��������ض�ͷԪ�ص�ֵ��true����Ϊ�գ�����false
template <class T>
bool LinkedQueue<T>::getFront(T &x) const
{
    if (isEmpty()) return false;                        //�ӿ�
    x = rear->link->data; return true;                  //ȡ����ͷԪ���е�����ֵ
}

//�������Ԫ�ظ���
template <class T>
int LinkedQueue<T>::getSize() const
{
    LinkNode<T> *p = rear->link; int k = 0;
    while (p->link != rear->link) {p = p->link; k++;} return k;
}

//����������������������Ԫ��
template <class T>
ostream &operator << (ostream &os, LinkedQueue<T> &Q)
{
    os << "�����е�Ԫ����" << Q.getSize() << endl;
    LinkNode<T> *p = Q.rear; int i = 0;
    while (p->link != Q.rear->link)
    {
        os << ++i << ":" << p->data << endl;
        p = p->link;
    } return os;
}
#endif //QUEUE_H