/*
小明参加一场考试，时间120分钟，需要拿最高分数

代表4门课，前俩数代表做一部分需要的时间和得到的分数，后俩数代表全做花费的时间和得到的分数

输入：
4
20 20 100 60
50 30 80 55
100 60 110 88
5 3 10 6

输出:
94

*/

#include <iostream>
using namespace std;

#define MAXSIZE 100
int w[MAXSIZE][2];
int v[MAXSIZE][2];
int maxv;
int n;
int dp1[MAXSIZE][MAXSIZE];
int dp2[MAXSIZE][MAXSIZE];
int dp[MAXSIZE][MAXSIZE];

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	maxv = 120;
	cin >> n ;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i][0] >> v[i][0] >> w[i][1] >> v[i][1];
	}
	for (int i = 0; i <= maxv; i++)
	{
		dp1[0][i] = 0;
		dp2[0][i] = 0;
		dp[0][i] = 0;
	}
		

	for (int i = 1; i <= n; i++)
	{
		//只有当j >= w[i],dp[i][j]才能进行选取最大值
		for (int j = maxv; j >= w[i][0]; j--)
		{
			dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - w[i][0]] + v[i][0]);
		}

		//当j < w[i]，说明第i个物品是不能转入背包的，故dp[i][j] = dp[i-1][j]
		for (int j = w[i][0] - 1; j >= 0; j--)
			dp1[i][j] = dp1[i - 1][j];

		//只有当j >= w[i],dp[i][j]才能进行选取最大值
		for (int j = maxv; j >= w[i][1]; j--)
		{
			dp2[i][j] = max(dp2[i - 1][j], dp2[i - 1][j - w[i][1]] + v[i][1]);
		}

		//当j < w[i]，说明第i个物品是不能转入背包的，故dp[i][j] = dp[i-1][j]
		for (int j = w[i][1] - 1; j >= 0; j--)
			dp2[i][j] = dp2[i - 1][j];

		for (int j = maxv; j >= 0; j--)
		{
			dp[i][j] = max(dp1[i][j], dp2[i][j]);
			dp1[i][j] = dp2[i][j] = dp[i][j];
		}
			
	}

	cout << dp[n][maxv] << endl;

	//while (1);
	return 0;
}




