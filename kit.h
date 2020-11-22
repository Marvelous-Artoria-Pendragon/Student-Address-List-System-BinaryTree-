/*�Զ��帨������*/
#ifndef KIT_H
#define KIT_H
#include <string.h>
#include <sstream>
#include <iostream>
#include <regex>
#include <stdio.h>
using namespace std;

//**��ȡָ����ʽ���ݺ���*
//���ض�ȡ��Ӧ��ʽ�Ļ�����������
//itemΪ��ȡ���ݵĶ���
//formatΪ��ȡ�ĸ�ʽ(����������ʽ,Ĭ���κ��ַ�����ƥ��ɹ�)
//input_promtΪ������ʾ�Ĭ��Ϊ�������룺��,��ʾ�ｫ���ڡ����롯�ֶκ�
//error_promtΪ����������ʾ�Ĭ��Ϊ'������Ч�ĸ�ʽ������������:'
template <typename T>
void getData(T &item, string format = ".+", string input_prompt = "", string error_promt = "������Ч�ĸ�ʽ������������:")
{
    string temp; cout << "������" << input_prompt << "��";
    stringstream ss;
    while (getline(cin, temp), !regex_match(temp, regex(format)))      //ƥ�������ַ���������������˳�ѭ��
    cout << error_promt;
    ss << temp; ss >> item;
}

//**��ȡָ����ʽ���ݺ���*
//���ض�ȡ��Ӧ��ʽ���ַ���
//itemΪ��ȡ���ݵĶ���
//formatΪ��ȡ�ĸ�ʽ(����������ʽ,Ĭ���κ��ַ�����ƥ��ɹ�)
//input_promtΪ������ʾ�Ĭ��Ϊ�������룺��,��ʾ�ｫ���ڡ����롯�ֶκ�
//error_promtΪ����������ʾ�Ĭ��Ϊ'������Ч�ĸ�ʽ������������:'
template<int n>
void getString(char (&item)[n], string format = ".+", string input_prompt = "", string error_promt = "������Ч�ĸ�ʽ������������:")
{
    string temp; cout << "������" << input_prompt << "��";
    while (getline(cin, temp), !regex_match(temp, regex(format)))      //ƥ�������ַ���������������˳�ѭ��
    cout << error_promt;
    strcpy(item, temp.c_str());
}



/*��ȡ�߾���ʱ���
void test4()
{
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    foo();//dosomething
    QueryPerformanceCounter(&t2);
    printf("Use Time:%f\n",(t2.QuadPart - t1.QuadPart)*1.0/tc.QuadPart);
}
*/

#endif //KIT_H