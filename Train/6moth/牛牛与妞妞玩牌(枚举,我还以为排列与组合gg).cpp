/*
牛牛与妞妞闲来无聊，便拿出扑克牌来进行游戏。游戏的规则很简单，两个人随机抽取四张牌，四张牌的数字和最大的取胜（该扑克牌总张数为52张，没有大小王，A=1，J=11，Q=12，K=13，每种数字有四张牌），现在两人已经分别亮出了自己的前三张牌，牛牛想要知道自己要赢得游戏的概率有多大。
输入描述:

输入包含两行，第一行输入三个整数a1，b1，c1(1≤a1，b1，c1≤13)，表示牛牛亮出的扑克牌。第二行输入三个整数a2，b2，c2(1≤a2，b2，c2≤13)，表示妞妞所亮出的扑克牌。



输出描述:

输出一个数字x（保留4位小数），表示牛牛获胜的概率。


输入例子1:

3 5 7
2 6 8


输出例子1:

0.3995
*/

/*
好难啊，啥也不会啊  排列组合不能判断里面的大小情况，想判断只能枚举了
*/

#include<iostream>
#include<string.h>
using namespace std;

int a[60];    //存放牌的数组，捡到了不算了
int a1,b1,c1,a2,b2,c2;
int vis[15];    //存放俩人捡到的牌的数量

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d", &a1, &b1, &c1);
    vis[a1]++;
    vis[b1]++;
    vis[c1]++;
    scanf("%d%d%d", &a2, &b2, &c2);
    vis[a2]++;
    vis[b2]++;
    vis[c2]++;
    
    int sum1 = a1 + b1 + c1;
    int sum2 = a2 + b2 + c2;
    
    int cnt=0;   //最后记录数量
    for(int i=1;i<=13;i++)
    {
        for(int j=0;j<4-vis[i];j++)
        {
            a[cnt++]=i;
        }
    }
    
    double l=0,r=0;
    for(int i=0;i<cnt;i++)     //枚举所有情况
    {
        sum1+=a[i];
        for(int j=0;j<cnt;j++)
        {
            if(i == j)
                continue;
            sum2+=a[j];
            r++;         //总情况
            if(sum1>sum2)
                l++;     //大于的情况
            sum2-=a[j];
        }
        sum1-=a[i];
    }
    printf("%.4f\n",l/r);  
    
    
    return 0;
}
