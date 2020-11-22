#include "Student.h"
#include "kit.h"
//�������캯��   
Student::Student(const Student &s)
{
    strcpy_s(name, s.name);
    strcpy_s(sex, s.sex);
    strcpy_s(number, s.number);
    birthday = s.birthday;
    strcpy_s(phonenum, s.phonenum);
    strcpy_s(addr, s.addr);
}

//��������������һ��ѧ����������Ϣ
ostream &operator << (ostream &output, const Student &s)
{
    cout << "����:" << s.name << endl
    << "�Ա�:" << s.sex << endl
    << "ѧ��:" << s.number << endl
    << "��������:" << (s.birthday >> 9) << "��" << (s.birthday << 23 >> 28) << "��" << (s.birthday << 27 >> 27) << "��" << endl
    << "�ֻ���:" << s.phonenum << endl
    << "��ַ:" << s.addr << endl;
    return output;
}

//����������������һ��ѧ����������Ϣ
istream &operator >> (istream &in, Student &s)
{
    getData(s.name, ".{1,20}", "����");
    getData(s.sex, "\\W{2}", "�Ա�(��/Ů)");
    getData(s.number, "\\d{1,20}", "ѧ��(�20λ)");            //����ȡ20λ����
    unsigned temp = 0;
    getData(temp, "\\d+", "�������"); s.birthday = temp;
    getData(temp, "[1-9]|([1][0-2])", "�����·�");
    s.birthday = (s.birthday << 4) + temp;
    getData(temp, "([1-2][0-9])|([1-9])|([3][0-1])", "��������");
    s.birthday = (s.birthday << 5) + temp;
    getData(s.phonenum,  "\\d{11}", "�ֻ���(11λ)");
    getData(s.addr, ".{1,100}", "��ַ");
    return in;
}

//����������ѧ����ؼ����е���
bool Student::operator == (const char key[21]) 
{return strcmp(name, key) == 0 || strcmp(number, key) == 0 || strcmp(phonenum, key) == 0 ? true : false;}

//����������ؼ����д���
bool Student::operator > (const unsigned &key) {return birthday > key ? true : false;}

//����������ؼ����е���
bool Student::operator == (const unsigned &key) {return birthday == key ? true : false;}

//����������ؼ�����С��
bool Student::operator < (const unsigned &key) {return birthday > key ? true : false;} 