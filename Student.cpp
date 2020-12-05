/*ѧ����*/
/*
��ʷ�汾�� v1.0
          v2.0 ��������ʹ��unsigned �洢
          v3.0 ����������ѧ�š��绰������ؼ����е��ڵĲ�������
              ����������ؼ���������жϲ�����
��ǰ�汾�� v3.0
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

struct Student
{
    Student() {};
    Student(const Student &s);                                          //�������캯��
    char name[21];                                                      //����(20λ�ַ�)
    char sex[3];                                                        //�Ա���/Ů
    char number[21];                                                    //ѧ��(20λ����)
    unsigned birthday;                                                  //�������ڣ�1~23λ�洢��ݣ�24~27�洢�·ݣ�28~32�洢����
    char phonenum[12];                                                  //�ֻ���
    char addr[50];                                                      //��ַ
    bool operator == (const char key[21]);                              //����������ѧ�š��绰������ؼ����е���
    bool operator > (const unsigned &key);                              //����������ؼ����д���(��ֵΪ���Ա)
    bool operator == (const unsigned &key);                             //����������ؼ����е���(��ֵΪ���Ա)
    bool operator < (const unsigned &key);                              //����������ؼ�����С��(��ֵΪ���Ա)
    friend bool operator > (const unsigned &key, const Student &s);     //����������ؼ����д���(��ֵΪ���Ա)
    friend bool operator == (const unsigned &key, const Student &s);    //����������ؼ����е���(��ֵΪ���Ա)
    friend bool operator < (const unsigned &key, const Student &s);     //����������ؼ�����С��(��ֵΪ���Ա)
    friend bool operator > (const Student &s1, const Student &s2);      //ѧ��֮�䰴����Ƚ�
    friend bool operator == (const Student &s1, const Student &s2);     //ѧ��֮�䰴����Ƚ�
    friend bool operator < (const Student &s1, const Student &s2);      //ѧ��֮�䰴����Ƚ�
    friend ostream &operator << (ostream &out, const Student &s);       //��������������һ��ѧ����������Ϣ
    friend istream &operator >> (istream &in, Student &s);              //����������������һ��ѧ����������Ϣ
};
#endif //STUDENT_H