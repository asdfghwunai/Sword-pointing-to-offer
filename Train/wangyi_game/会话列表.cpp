/*


小云正在参与开发一个即时聊天工具，他负责其中的会话列表部分。

会话列表为显示为一个从上到下的多行控件，其中每一行表示一个会话，每一个会话都可以以一个唯一正整数id表示。

当用户在一个会话中发送或接收信息时，如果该会话已经在会话列表中，则会从原来的位置移到列表的最上方；如果没有在会话列表中，则在会话列表最上方插入该会话。
小云在现在要做的工作是测试，他会先把会话列表清空等待接收信息。当接收完大量来自不同会话的信息后，就输出当前的会话列表，以检查其中是否有bug。
输入描述:

输入的第一行为一个正整数T（T<=10），表示测试数据组数。
接下来有T组数据。每组数据的第一行为一个正整数N（1<=N<=200），表示接收到信息的次数。第二行为N个正整数，按时间从先到后的顺序表示接收到信息的会话id。会话id不大于1000000000。



输出描述:

对于每一组数据，输出一行，按会话列表从上到下的顺序，输出会话id。
相邻的会话id以一个空格分隔，行末没有空格。


输入例子1:

3
5
1 2 3 4 5
6
1 100 1000 1000 100 1
7
1 6 3 3 1 8 1


输出例子1:

5 4 3 2 1
1 100 1000
1 8 3 6


*/

#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int T=0;
int main()
{
    cin>>T;
    for(int T_num=0;T_num<T;T_num++)
    {
        int N=0,in=0;
        vector<int> src;
        unordered_set<int> src_set;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>in;
            src.push_back(in);
        }


        for(int i =src.size()- 1; i>=0;i--)
        {
            if(src_set.find(src[i])==src_set.end())  //没找到
            {
                src_set.insert(src[i]);
                cout<<src[i]<<" ";
            }
        }
        cout<<endl;
    }


    return 0;
}
