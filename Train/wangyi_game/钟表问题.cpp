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
