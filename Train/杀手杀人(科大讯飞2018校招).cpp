/*
有个杀手要杀人，只能杀相邻的右边比自己编号小的

输入:
10
10 9 7 8 6 5 3 4 2 1

输出
2

输入第一个是人数，第二行是1-n的排列

输入:
6
1 2 3 4 5 6

输出:
0
*/

#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

int a[100000];
int main()
{
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    int count=0;
    while(1)
    {
        int first=1;
        int flag=0;
        count++;    //计数
        for(int i=1;i<n;i++)
        {

            if(a[i]<a[i-1])
            {
                flag=1;
                continue;
            }

            a[first]=a[i];
            first++;
        }
        n=first;     //重置数量
        if(flag==0)
            break;
    }
    cout<<count-1<<endl;

    return 0;
}
