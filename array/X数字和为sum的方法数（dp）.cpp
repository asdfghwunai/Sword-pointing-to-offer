/*
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
输入描述:

输入为两行:

第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)

第二行为n个正整数A[i](32位整数)，以空格隔开。



输出描述:

输出所求的方案数

示例1
输入

5 15
5 5 10 2 3

输出

4

*/

#include<iostream>
using namespace std;
 
 
//dp[i][j]表示用前i个值组成和为j的方案个数。
//最终结果int类型存不下，需要64位数据。
//注意：dp不能放在main里，栈存不下，需要放在全局数据区。
int main()
{
	long long dp[10001][10001];
	int n, sum;
	cin >> n >> sum;
	int data[1000];
	for (int i = 1; i <=n; i++)
	  {
		cin >> data[i];
	  }
//用0个元素不能组成1~sum
	for (int j = 1; j < sum; j++)
		dp[0][j] = 0;                     //zk 下标0是用到的种类数，下标j是构成的总钱数
//初始化dp，用前i个数组成和为0的方案，只有1种，就是什么都不取，和为0。
	for (int i = 0; i < n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (data[i] > j)  //当前元素data[i]的值大于当前的和j，则只能取前面i-1个元素和值为j的个数
				dp[i][j] = dp[i - 1][j];
			else //当前元素data[i]的值小于或等于当前的和j，则可以取前面i-1个元素和值为j的个数或者前面i-1个元素和值为j-data[i]的个数
				dp[i][j] = dp[i-1][j]+dp[i-1][j-data[i]];
		}
	}
	cout << dp[n][sum] << endl;
}
