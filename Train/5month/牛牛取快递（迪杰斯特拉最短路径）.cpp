/*
 牛牛的快递到了，他迫不及待地想去取快递，但是天气太热了，以至于牛牛不想在烈日下多走一步。他找来了你，请你帮他规划一下，他最少要走多少距离才能取回快递。
输入描述:

每个输入包含一个测试用例。
输入的第一行包括四个正整数，表示位置个数N(2<=N<=10000)，道路条数M(1<=M<=100000)，起点位置编号S(1<=S<=N)和快递位置编号T(1<=T<=N)。位置编号从1到N，道路是单向的。数据保证S≠T，保证至少存在一个方案可以从起点位置出发到达快递位置再返回起点位置。
接下来M行，每行包含三个正整数，表示当前道路的起始位置的编号U(1<=U<=N)，当前道路通往的位置的编号V(1<=V<=N)和当前道路的距离D(1<=D<=1000)。



输出描述:

对于每个用例，在单独的一行中输出从起点出发抵达快递位置再返回起点的最短距离。


输入例子1:

3 3 1 3 
1 2 3 
2 3 3 
3 1 1


输出例子1:

7


*/

/*
答案解析上说就是求两次路径，从s到t和从t到s
*/

#include <iostream>
#include <stdio.h>
#include <memory.h>
#include<vector>
#include<queue>
using namespace std;

struct Edge
{
	int dis, to;
	bool friend operator <(Edge x1, Edge x2)
	{
		return x1.dis>x2.dis;
	}
}temp, now;
vector <Edge> vec[10005];  //所有边，下标是起点，里面的节点保存了长度和终点
bool life[10005];
int dis[10005], n;
priority_queue <Edge> q;

void init()
{
	for (int i = 1; i <= n; i++)
		dis[i] = 100000000;
	memset(life, 0, sizeof(life));
	while (!q.empty())
		q.pop();
}
int dij(int s, int t)    //应该是迪杰斯特拉，就当这个函数是标准函数就行了
{
	init();    //重新初始化
	temp.to = s;
	temp.dis = 0;
	q.push(temp);
	dis[s] = 0;
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (!life[now.to])
		{
			life[now.to] = 1;
			for (int i = 0; i<vec[now.to].size(); i++)
			{
				if (!life[vec[now.to][i].to] && dis[now.to] + vec[now.to][i].dis<dis[vec[now.to][i].to])
				{
					dis[vec[now.to][i].to] = dis[now.to] + vec[now.to][i].dis;
					temp.to = vec[now.to][i].to;
					temp.dis = dis[vec[now.to][i].to];
					q.push(temp);
				}
			}
		}
	}
	return dis[t];
}

int main()
{
	int m, s, t, u, v, d;
	scanf("%d%d%d%d", &n, &m, &s, &t);    //n是地点个数，m是边的个数，s是起点，t是终点
	while (m--)
	{
		scanf("%d%d%d", &u, &v, &d);
		temp.dis = d;
		temp.to = v;
		vec[u].push_back(temp);
	}
	printf("%d\n", dij(s, t) + dij(t, s));
	return 0;
}
