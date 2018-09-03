#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct MS
{
	int l;
	int r;
} data1[50005],data2[50005]; //区间

int comp(const struct MS &a, const struct MS &b)
{
	return a.l < b.l || a.l == b.l && a.r < b.r; //左端点升序，相等时右端点升序
}

int main()
{
	int a;
	
	scanf("%d", &a);
	int x, y;
	for (int i = 0; i < a; i++)
	{
		scanf("%d%d", &x, &y);
		data2[i].l = data1[i].l=x;     //暂存以前的
		data2[i].r = data1[i].r=x+y-1;
	}
	sort(data1, data1 + a, comp);


	for (int j = 0; j < a; j++)
	{
		int maxr = 0; //记录目前最大右端点
		maxr = data2[j].r;
		int sum = 1;     //自己的
		int flag1 = 0;
		int flag2 = 0;
		for (int i = 0; i < a-1; i++) //注意这里少统计了一个data1[a-1]的右端点
		{
			flag1 = 1; //说明进去过
			if (data1[i].l >= data2[j].l+1)  //必须是在当前基准的右边才算
				sum++;

			if (data1[i].l >= data2[j].l + 1 && data1[i].r > maxr)  //必须是在当前基准的右边才算
				maxr = data1[i].r;

			if (!(data1[i + 1].l <= maxr)) //与之前出现的最大的右端点作比较
			{
				//printf("no");
				//return 0;
				flag2 = 1;    //说明没满足条件
				break;
			}
		}
	

		if (data1[a - 1].l <= maxr && data1[a - 1].l >= data2[j].l + 1) //必须是在当前基准的右边才算
			sum += 1;

		cout << sum << " ";
	}
	
	while (1);
	return 0;
}

/*
2
1 3 
2 4

4
16 5
20 5
10 10
18 2
*/
