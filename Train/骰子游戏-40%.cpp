/*
链接：https://www.nowcoder.com/questionTerminal/0e83797c34e54cca91179fe9ad681bc4
来源：牛客网

小易参加了一个骰子游戏,这个游戏需要同时投掷n个骰子,每个骰子都是一个印有数字1~6的均匀正方体。
小易同时投掷出这n个骰子,如果这n个骰子向上面的数字之和大于等于x,小易就会获得游戏奖励。
小易想让你帮他算算他获得奖励的概率有多大。 
输入描述:
输入包括两个正整数n和x(1 ≤ n < 25, 1 ≤ x < 150),分别表示骰子的个数和可以获得奖励的最小数字和。


输出描述:
输出小易可以获得奖励的概率。
如果概率为1,输出1,如果概率为0,输出0,其他以最简分数(x/y)的形式输出。
示例1
输入
3 9
输出
20/27
*/

/*
好像还是递归的问题啊，老是复杂度太大
*/

#include <stdio.h>
#include <string.h>
#include<math.h>

#include <iostream>
using namespace std;

/****************************
func:获取n个骰子指定点数和出现的次数
para:n:骰子个数;sum:指定的点数和
return:点数和为sum的排列数
****************************/
int getNSumCount(int n, int sum){
    if(n<1||sum<n||sum>6*n){
        return 0;
    }
    if(n==1){
        return  1;
    }
    int resCount=0;
    resCount=getNSumCount(n-1,sum-1)+getNSumCount(n-1,sum-2)+
             getNSumCount(n-1,sum-3)+getNSumCount(n-1,sum-4)+
             getNSumCount(n-1,sum-5)+getNSumCount(n-1,sum-6);
    return resCount;
}

int gcd(int a,int b)  //求公约数
{   int c;  
    c=(a>b)?b:a;  
    while(a%c!=0||b%c!=0)  
    {   c--;  
    }  
    return c;  
} 

int main()
{
    int n,x;
    cin>>n>>x;
    
    int count=0;
    for(int i=x;i<=6*n;i++)
        count+=getNSumCount(n,i);
    int total=pow(6,n);   //总数
    if(count==0)
    {
        cout<<0;
        return 0;
    }
    if(count==total)
        return 1;
      
    int yueshu=gcd(count,total);
     
    cout<<count/yueshu<<"/"<<total/yueshu;
    return 0;
}
