#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>
using namespace std;
//const int STACK_INCREASMENT = 20;           //ջ���ʱ��չ�ռ������
//const int MAX_SIZE = 50;

template <class T>
class Stack
{
    public:
        Stack(){};  //���캯��
        virtual void push(const T &x) = 0;      //��Ԫ��x��ջ
        virtual bool pop(T &x) = 0;             //ջ��Ԫ�س�ջ����x����
        virtual bool getTop(T &x) const = 0;    //��ȡջ��Ԫ�أ���x����
        virtual bool isEmpty() const = 0;       //�ж�ջ�Ƿ�Ϊ��
        virtual bool isFull() const = 0;        //�ж�ջ�Ƿ�Ϊ��
        virtual int getSize() const = 0;        //����ջ��Ԫ�ظ���
};

//˳��ջ
template <class T>
class SeqStack: public Stack<T>
{
    public:
        SeqStack(int sz = 50);                              //����һ����ջ
        ~SeqStack() {delete[] elements;}                    //��������
        virtual void push(const T &x);                      //���isFull(),��������������x���뵽ջ��ջ��
        virtual bool pop(T &x);                             //ȡ��ջ��Ԫ�أ���ֵ��x
        virtual bool getTop(T &x) const;                    //��ȡջ��Ԫ�صĿ�����x����ɾ��ջ��Ԫ��
        virtual bool isEmpty() const {return (top == -1) ? true:false;}             
        virtual bool isFull() const {return (top == maxSize - 1) ? true:false;}
        virtual int getSize() const {return top + 1;}
        void makeEmpty() {top = -1;}                        //���ջ������
        //���ջ��Ԫ�صĲ���
        template <class Y>
        friend ostream &operator <<(ostream &os, SeqStack<Y> &s);
    private:
        T *elements;                //���ջ��Ԫ�ص�ջ����
        int top;                    //ջ��ָ��
        int maxSize;                //ջ��������Ԫ�ظ���
        void overflowProcess();     //ջ�������
};

template <class T>
SeqStack<T>::SeqStack(int sz): top(-1), maxSize(sz)
{
    //����һ�����ߴ�Ϊsz�Ŀ�ջ
    elements = new T[maxSize];      //����ջ������ռ�
    assert(elements != NULL);
};


template <class T>
void SeqStack<T>::overflowProcess ()
{
    //����ջ�Ĵ洢�ռ�
    T *newArray = new T[2 * maxSize];
    if (newArray == NULL) {cerr << "�洢����ʧ�ܣ�" << endl; exit(1);}
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
    os << "top = " << s.top << endl;        //���ջ��λ��
    for (int i = 0; i <= s.top; i++)
        os << i << ":" << s.elements[i] << endl;
    return os;
};

#endif  //STACK_H