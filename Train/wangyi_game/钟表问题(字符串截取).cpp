/*

小W有一个电子时钟用于显示时间，显示的格式为HH:MM:SS，HH，MM，SS分别表示时，分，秒。
其中时的范围为[‘00’,‘01’…‘23’]，分的范围为[‘00’,‘01’…‘59’]，秒的范围为[‘00’,‘01’…‘59’]。

但是有一天小W发现钟表似乎坏了，显示了一个不可能存在的时间“98:23:00”，小W希望改变最少的数字，使得电子时钟显示的时间为一个真实存在的时间，
譬如“98:23:00”通过修改第一个’9’为’1’，即可成为一个真实存在的时间“18:23:00”。修改的方法可能有很多，小W想知道，在满足改变最少的数字的前提下，
符合条件的字典序最小的时间是多少。
其中字典序比较为用“HHMMSS”的6位字符串进行比较。 
*/

/*
不用管:
满足改变最少的数字的前提下,直接把不符合的字符串改小就行
*/

#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
int num=0;
string src;
int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>src;
        //处理
        int wei1=src.find(":",0);   //开头搜索第一个:
        int wei2=src.find(":",wei1+1);   //接着搜索第一个:
        string hh=src.substr(0,2);
        string mm=src.substr(wei1+1,2);
        string ss=src.substr(wei2+1,2);
        int hh_num=atoi(hh.c_str());
        int mm_num=atoi(mm.c_str());
        int ss_num=atoi(ss.c_str());

        if(hh_num>23)
        {
            hh_num=hh_num%10;
            hh='0'+to_string(hh_num);
        }
        if(mm_num>59)
        {
            mm_num=mm_num%10;
            mm='0'+to_string(mm_num);
        }

        if(ss_num>59)
        {
            ss_num=ss_num%10;
            ss='0'+to_string(ss_num);
        }
        cout<<hh<<":"<<mm<<":"<<ss<<endl;
    }

    return 0;
}
