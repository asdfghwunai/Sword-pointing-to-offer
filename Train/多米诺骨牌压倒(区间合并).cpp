/*
多米诺骨牌
第一行输入是牌的个数n
第二行是牌的位置和高度(x,h)

牌只能压倒[x+1,x+h-1]位置的其他牌
请输出n个数，代表各个位置牌能压倒的个数

输入：
4
16 5
20 5
10 10
18 2

输出：
3 1 4 1
*/

/*
失败总结：
题都没搞明白；
写的程序没想清楚，没看出错误；
思维太乱，光看着题找bug就是想象不出来，得画画啊，画熟了再脑子想
*/
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
		
		for (int i = 0; i < a-1; i++) //注意这里少统计了一个data1[a-1]的右端点 //这里我出错了，刚开始写成i=j什么的，但在data2中那个位置不说明在data1也是那个位置啊
		{
			
			if (data1[i].l >= data2[j].l+1)  //必须是在当前基准的右边才算 //注意相同起点压不倒的
				sum++;

			if (data1[i].l >= data2[j].l + 1 && data1[i].r > maxr)  //必须是在当前基准的右边才算
				maxr = data1[i].r;

			if (!(data1[i + 1].l <= maxr)) //与之前出现的最大的右端点作比较
			{
				//printf("no");
				//return 0;
	
				break;
			}
		}
	
		//看最后一个区间
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
