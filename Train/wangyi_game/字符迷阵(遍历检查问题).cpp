/*
 字符迷阵是一种经典的智力游戏。玩家需要在给定的矩形的字符迷阵中寻找特定的单词。
在这题的规则中，单词是如下规定的：
1. 在字符迷阵中选取一个字符作为单词的开头；
2. 选取右方、下方、或右下45度方向作为单词的延伸方向；
3. 以开头的字符，以选定的延伸方向，把连续得到的若干字符拼接在一起，则称为一个单词。 

以图1为例，如果要在其中寻找单词"WORD"，则绿色框所标示的都是合法的方案，而红色框所标示的都是不合法的方案。
现在的问题是，给出一个字符迷阵，及一个要寻找的单词，问能在字符迷阵中找到多少个该单词的合法方案。注意合法方案是可以重叠的，如图1所示的字符迷阵，
其中单词"WORD"的合法方案有4种。 
*/

/*
就是写三个函数检测一下右边,下边,右下边符不符合
用原生字符串做,注意怎么输入字符串
*/


#include<iostream>
#include<string.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
char zimu[101][101];
char target[10];
int T=0;
 
int check_one(char *target,int i,int j,int row,int col)   //查询右边
{
    int len=strlen(target);
    if(j+len-1>col-1)   //过长
        return 0;
    char *val=(char *)malloc(sizeof(len+1));
    for(int x=0;x<len;x++)
        val[x]=zimu[i][j+x];  //复制
    val[len]='\0';
 
    if(strcmp(val,target)==0)
        return 1;
    else
        return 0;
}
 
int check_two(char *target,int i,int j,int row,int col)    //查询下边
{
    int len=strlen(target);
    if(i+len-1>row-1)   //过长
        return 0;
    char *val=(char *)malloc(sizeof(len+1));
    for(int x=0;x<len;x++)
        val[x]=zimu[i+x][j];  //复制
    val[len]='\0';
 
    if(strcmp(val,target)==0)
        return 1;
    else
        return 0;
}
 
int check_three(char *target,int i,int j,int row,int col)   //查询右下
{
    int len=strlen(target);
    if(j+len-1>col-1 || i+len-1>row-1)   //过长
        return 0;
    char *val=(char *)malloc(sizeof(len+1));
    for(int x=0;x<len;x++)
        val[x]=zimu[i+x][j+x];  //复制
    val[len]='\0';
 
    if(strcmp(val,target)==0)
        return 1;
    else
        return 0;
}
 
int main()
{
    cin>>T;
    for(int T_num=0;T_num<T;T_num++)
    {
        int m=0,n=0;
        memset(zimu,'\0',sizeof(zimu));
        memset(target,'\0',sizeof(target));
 
        cin>>m>>n;
        for(int i=0;i<m;i++)     //进行输入
            scanf("%s",zimu[i]);
        scanf("%s",target);
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res+=check_one(target,i,j,m,n);
                res+=check_two(target,i,j,m,n);
                res+=check_three(target,i,j,m,n);
            }
        }
 
        cout<<res<<endl;
    }
 
 
    return 0;
}
