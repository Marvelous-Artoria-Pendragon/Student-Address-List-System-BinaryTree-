/*
��Ŀ����ѧ��ͨѶ¼����ϵͳ
���ߣ����Ӻ�
�����޸����ڣ�2020/11/22
�汾��ʷ��Ϣ��v1.0              �����������
             v2.0              �޸��˶�����Ѱ�ұ��Ϊn�Ľ���㷨��bug
                               �ļ���д·����Ϊ�����ȡ
��ǰ�汾�ţ�v2.0
*/
#ifndef MENU_CPP
#define MENU_CPP
#include "Student.h"        //Student��
#include "System.h"         //System��
#include "kit.h"

int main()
{
    short op;                                 //����Ĳ���ѡ��
    System<Student> p;                        //ѧ��������
    void (System<Student>::*option[11])() = {&System<Student>::create, &System<Student>::insert, &System<Student>::searchByNumber,
                &System<Student>::searchByName, &System<Student>::searchByPhonenum, &System<Student>::del,
                &System<Student>::displayYoungestStudent, &System<Student>::display, &System<Student>::readFromFile, 
                &System<Student>::writeToFile, &System<Student>::createData};
    cout << "**************ѧ��ͨѶ¼����ϵͳ***************\n";
    while (1)
    {
        cout << "=========================================\n"
            << "ϵͳ�Ĳ˵����������£�\n"
            << "1------�½�ѧ��������\n"
            << "2------��ѧ��ͨѶ¼����ѧ����Ϣ\n"
            << "3------��ͨѶ¼�в�ѯѧ����Ϣ(��ѧ�Ų�ѯ)\n"
            << "4------��ͨѶ¼�в�ѯѧ����Ϣ(��������ѯ)\n"
            << "5------��ͨѶ¼�в�ѯѧ����Ϣ(���绰�����ѯ)\n"
            << "6------��ͨѶ¼ɾ��ѧ����Ϣ\n"
            << "7------���������С��ѧ����Ϣ\n"
            << "8------����Ļ�����ȫ��ѧ����Ϣ\n"
            << "9------���ļ��ж�ȡͨѶ¼��Ϣ\n"
            << "10-----���ļ�д��ѧ��ͨѶ¼��Ϣ\n"
            << "11-----�������ݼ�\n"
            << "12-----�˳�\n"
            << "=========================================\n";
        getData(op, "[1-9]|([1][0-2])", "ִ�еĲ���"); cout << endl;
        if (op == 12) exit(0);
        (p.*option[op - 1])();
    }
}
#endif //MENU_CPP