/*自定义辅助函数*/
#ifndef KIT_H
#define KIT_H
#include <string.h>
#include <sstream>
#include <iostream>
#include <regex>
#include <stdio.h>
using namespace std;

//**读取指定格式数据函数*
//返回读取对应格式的基本类型数据
//item为获取数据的对象
//format为读取的格式(采用正则表达式,默认任何字符都能匹配成功)
//input_promt为输入提示语，默认为‘请输入：’,提示语将加在‘输入’字段后
//error_promt为错误输入提示语，默认为'不是有效的格式，请重新输入:'
template <typename T>
void getData(T &item, string format = ".+", string input_prompt = "", string error_promt = "不是有效的格式，请重新输入:")
{
    string temp; cout << "请输入" << input_prompt << "：";
    stringstream ss;
    while (getline(cin, temp), !regex_match(temp, regex(format)))      //匹配整个字符串，整个满足才退出循环
    cout << error_promt;
    ss << temp; ss >> item;
}

//**读取指定格式数据函数*
//返回读取对应格式的字符串
//item为获取数据的对象
//format为读取的格式(采用正则表达式,默认任何字符都能匹配成功)
//input_promt为输入提示语，默认为‘请输入：’,提示语将加在‘输入’字段后
//error_promt为错误输入提示语，默认为'不是有效的格式，请重新输入:'
template<int n>
void getString(char (&item)[n], string format = ".+", string input_prompt = "", string error_promt = "不是有效的格式，请重新输入:")
{
    string temp; cout << "请输入" << input_prompt << "：";
    while (getline(cin, temp), !regex_match(temp, regex(format)))      //匹配整个字符串，整个满足才退出循环
    cout << error_promt;
    strcpy(item, temp.c_str());
}

//快排，arr为数组，left为开始序号，right为结束序号，reverse=false为升序，true为降序
template <typename T>
void quicksort(T *arr, int left, int right, bool reverse = false)
{
    if (!reverse)
    {
        T mid = arr[(left + right) / 2],            //中间数为基准
        low = left, high = right;
        do
        {
            while (arr[low] < mid) low++;
            while (arr[high] > mid) high--;
            if (low <= high) 
                {swap(arr[low], arr[high]); low++; high--;}
        } while (low <= high);
    }
    else
    {
        T mid = arr[(left + right) / 2],            //中间数为基准
        low = left, high = right;
        do
        {
            while (arr[low] > mid) low++;
            while (arr[high] < mid) high--;
            if (low <= high) 
                {swap(arr[low], arr[high]); low++; high--;}
        } while (low <= high);
    }
    if (left < high) quicksort(arr, left, high, reverse);               //对左边部分排序
    if (low < right) quicksort(arr, low, right, reverse);              //对半部分排序
}



/*获取高精度时间戳
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