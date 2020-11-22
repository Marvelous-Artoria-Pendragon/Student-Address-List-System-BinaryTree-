#ifndef SYSTEM_H
#define SYSTEM_H
#include "CompleteBinaryTree.h"
#include <iostream>
#include <fstream>
#include "kit.h"
#include <stdio.h>
#include <ctime>
using namespace std;

template <class T>
class System                                            //ϵͳ��
{
    protected:
        CompleteBinaryTree<T> *bt;                          //�����������ָ��
        CompleteBinaryTree<T> *birthday;                    //��ѧ�����仮�ֵĶ���������
        template <typename Y>
        friend void getData(Y &, string, string, string);   //��ȡָ����ʽ�����ݺ���
    public:
        System(): bt(new CompleteBinaryTree<T>), birthday(NULL){}       //���캯��,Ĭ��û�г�ʼֵ
        //System(const System<T> &);                        //�������캯��
        ~System(){delete bt;}                               //��������
        
        void create();                                      //�½�ѧ��ͨѶ¼(�Բ�α����ķ�ʽ����ѧ����Ϣ������)
        void insert();                                      //��ѧ��ͨѶ¼����ѧ����Ϣ
        void searchByNumber();                              //��ͨѶ¼�в�ѯѧ����Ϣ����ѧ�Ų�ѯ��
        void searchByName();                                //��ͨѶ¼�в�ѯѧ����Ϣ����������ѯ��
        void searchByPhonenum();                            //��ͨѶ¼�в�ѯѧ����Ϣ�����绰�����ѯ��
        void del();                                         //��ͨѶ¼ɾ��ѧ����Ϣ���Ȱ�����3-5�Ĳ�ѯ��ʽ��λ��ɾ��ѧ����
        void displayYoungestStudent();                      //���������С��ѧ����Ϣ
        void display();                                     //����Ļ�����ȫ��ѧ����Ϣ������ѡ������ǰ�����򡢺�������ķ�ʽ��
        void readFromFile();                                //���ļ��ж�ȡͨѶ¼��Ϣ
        void writeToFile();                                 //���ļ�д��ͨѶ¼��Ϣ
        void createData();                                  //����n������
};

//�½�ѧ��ͨѶ¼(�Բ�α����ķ�ʽ����ѧ����Ϣ������)
template <class T>
void System<T>::create()
{
    int n; getData(n, "\\d+", "������ѧ����");  
    if (n < 1) cout << "*******************�½�ʧ�ܣ�����ͨѶ¼��������Ϊ1��*********************" << endl;
    else {bt->CreateBinTree(cin, n); cout << "�½��ɹ���" << endl;}
}

//��ѧ��ͨѶ¼����ѧ����Ϣ
template <class T>
void System<T>::insert()
{
    clock_t startTime, endTime; T item; cin >> item; 
    startTime = clock(); bt->insert(item);              //��ʱ��ʼ
    cout << "************************����ɹ���**********************" << endl;
    endTime = clock();                 //��ʱ����
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//��ͨѶ¼�в�ѯѧ����Ϣ����ѧ�Ų�ѯ��
template <class T>
void System<T>::searchByNumber()
{
    clock_t startTime, endTime;
    if (bt->isEmpty()) {cout << "*****************************��ǰδ���κ�ͨѶ¼��¼��****************************\n"; return;}
    char number[21]; getData(number, "\\d{1,20}", "������ѧ��ѧ��"); startTime = clock();                //��ʱ��ʼ
    BinTreeNode<T> *temp = bt->find(number);
    if (temp != NULL) cout << "���ҵ���\n" << temp->data << endl;
    else cout << "************************δ�ҵ���ѧ����**************************" << endl;
    endTime = clock();                 //��ʱ����
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//��ͨѶ¼�в�ѯѧ����Ϣ����������ѯ��
template <class T>
void System<T>::searchByName()
{
    clock_t startTime, endTime;
    if (bt->isEmpty()) {cout << "*****************************��ǰδ���κ�ͨѶ¼��¼��****************************\n"; return;}
    char name[21]; getData(name, "[^\\d]{1,20}", "������ѧ������"); startTime = clock();                //��ʱ��ʼ
    BinTreeNode<T> *temp = bt->find(name);
    if (temp != NULL) cout << "���ҵ���\n" << temp->data << endl;
    else cout << "************************δ�ҵ���ѧ����**************************" << endl;
    endTime = clock();                 //��ʱ����
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//��ͨѶ¼�в�ѯѧ����Ϣ�����绰�����ѯ��
template <class T>
void System<T>::searchByPhonenum()
{
    clock_t startTime, endTime;
    if (bt->isEmpty()) {cout << "*****************************��ǰδ���κ�ͨѶ¼��¼��****************************\n"; return;}
    char phonenum[12]; getData(phonenum, "\\d{11}", "������ѧ���ĵ绰����"); startTime = clock();                //��ʱ��ʼ
    BinTreeNode<T> *temp = bt->find(phonenum);
    if (temp != NULL) cout << "���ҵ���\n" << temp->data << endl;
    else cout << "************************δ�ҵ���ѧ����**************************" << endl;
    endTime = clock();                 //��ʱ����
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//��ͨѶ¼ɾ��ѧ����Ϣ���Ȱ�����3-5�Ĳ�ѯ��ʽ��λ��ɾ��ѧ����
template <class T>
void System<T>::del()
{
    if (bt->isEmpty()) {cout << "*****************************��ǰδ���κ�ͨѶ¼��¼��****************************\n"; return;}
    cout << "1----------------ѧ��\n" << "2----------------����\n" << "3----------------�绰����\n";
    int op = 0; getData(op, "[1-3]", "��ѡ��ɾ����ѧ������Ϣ"); bool flag = false;                              //ɾ���ɹ���ʶ
    clock_t startTime, endTime;
    char data[3][21]; getData(data[op - 1], ".{1,20}");             //�洢�������ݵ��ַ�����
    startTime = clock();                //��ʱ��ʼ
    if (bt->remove(data[op - 1])) cout << "**************************ɾ���ɹ���****************************" << endl;
    else cout << "***********************δ�ҵ���ѧ���ļ�¼��ɾ��ʧ�ܣ�***************************" << endl;
    endTime = clock();                 //��ʱ����
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//���������С��ѧ����Ϣ
//ʹ�ò�α�����ѡ��Ѱ��������С��ѧ��
template <class T>
void System<T>::displayYoungestStudent()
{
    if (bt->isEmpty()) {cout << "*******************��ǰͨѶ¼δ���κμ�¼��*******************\n" << endl; return;}   //��Ϊ����ʾ
    clock_t startTime, endTime;
    startTime = clock();                //��ʱ��ʼ
    BinTreeNode<T> *root = bt->getRoot(), *temp = NULL, *youngest = root;             //������������С��ѧ�����ڽ��
    LinkedQueue<BinTreeNode<T> *> Q; Q.EnQueue(root);
    while (!Q.isEmpty())
    {
        Q.DeQueue(temp);
        if (temp->data.birthday > youngest->data.birthday) youngest = temp;
        if (temp->child[0] != NULL) Q.EnQueue(temp->child[0]);                    //����Ů����
        if (temp->child[1] != NULL) Q.EnQueue(temp->child[1]);                    //����Ů����
    }
    cout << "������С��ѧ����\n" << youngest->data << endl;
    endTime = clock();                 //��ʱ��ʼ
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//����Ļ�����ȫ��ѧ����Ϣ������ѡ������ǰ�����򡢺�������ķ�ʽ��
template <class T>
void System<T>::display()
{
    if (bt->isEmpty()) {cout << "************δ���κ�ͨѶ¼��Ϣ��**************" << endl; return;}
    cout << "1----ǰ�����\n" << "2----�������\n" << "3----�������\n";
    void (CompleteBinaryTree<T>::*arr[3])(void (*visit)(BinTreeNode<T> *current)) 
            = {&CompleteBinaryTree<T>::preOrder, &CompleteBinaryTree<T>::inOrder, &CompleteBinaryTree<T>::postOrder};
    int op; getData(op, "[1-3]", "������ʽ");
    static unsigned index = 0;                              //��ʶѧ������
    (bt->*arr[op - 1])([](BinTreeNode<T> *current) {cout << "��" << ++index << "��ѧ����\n" << current->data << endl;});
    index = 0;                                              //����ѧ������
}

//���ļ��ж�ȡͨѶ¼��Ϣ
template <class T>
void System<T>::readFromFile()
{
    clock_t startTime, endTime;
    char path[1000]; getString(path, ".+\\..+", "�ļ���");
    startTime = clock();                //��ʱ��ʼ
    if (bt->load(path)) cout << "****��ȡ�ɹ���****" << endl;
    else cout << "***********************�ļ���ʧ�ܣ�*************************" << endl;
    endTime = clock();                 //��ʱ����
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//���ļ�д��ͨѶ¼��Ϣ
template <class T>
void System<T>::writeToFile()
{
    clock_t startTime, endTime;
    char path[1000]; getString(path, ".+\\..+", "�ļ���");
    startTime = clock();                //��ʱ��ʼ
    if (bt->save(path)) cout << "****��ȡ�ɹ���****" << endl;
    else cout << "***********************�ļ��½�ʧ�ܣ�*************************" << endl;
    endTime = clock();                 //��ʱ����
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

//����n������
template <class T>
void System<T>::createData()
{
    unsigned n; getData(n, "\\d+", "��������"); T stu;
    char path[1000]; getString(path, ".+\\..+", "���ݼ��ļ���");
    ofstream outfile(path, ios::out | ios::binary);
    char version[] = "0xA0B0C0";                                           //��־�ļ��Ƿ���Ч
    outfile.write(version, 8);
    if (!outfile) {cerr << "**********************�ļ���ʧ�ܣ�**********************" << endl; return;}      //�ļ���ʧ��
    clock_t startTime, endTime;
    startTime = clock();                //��ʱ��ʼ
    const unsigned STU_SIZE = sizeof(stu);                                 //�ṹ���С
    for (int i = 1; i <= n; i++)
    {
        snprintf(stu.name, 21, "%d", i);
        snprintf(stu.sex, 3, "%s", "��");
        snprintf(stu.number, 21, "%d", i);
        stu.birthday = i;
        snprintf(stu.phonenum, 12, "12345678901");
        snprintf(stu.addr, 21, "beijing");
        outfile.write((char *) &stu, STU_SIZE);
    }
    endTime = clock();                //��ʱ��ʼ
    cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    outfile.close();
    cout << "***********************���ݴ����ɹ���***********************" << endl;
}
#endif //SYSTEM_H