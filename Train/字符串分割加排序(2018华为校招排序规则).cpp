/*
排序规则:
次数多的放后面
如果次数一样，大的放后面

输入:
a11b2bac3bad3abcd2
输出：
abcdabcdbbbacbacbacbadbadbadaaaaaaaaaaa

*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct node
{
	string x;
	int y;

	node()
	{
		x = "";
		y = 0;
	}
} ss[10000];

bool cmp(const node &A, const node &B)
{

	if (A.y != B.y)
		return A.y < B.y;
	else
	{
		return A.x <= B.x;
	}
}
int main()
{
	string str;
	cin >> str;

	int start = 0;
	int count = 0;
	int flag = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= '0' || str[i] >= '9'&&flag == 1)   //恢复
		{
			flag = 0;
			start = i;
			count++;
		}
			

		if (str[i] >= '0'&&str[i] <= '9'&&flag == 0)     //分割
		{
			ss[count].x = str.substr(start, i - start);
			flag = 1;
		}
		if (flag == 1)   //开始取数字
		{
			ss[count].y = ss[count].y * 10 + (str[i] - '0');
		}
			
			
	} 
	//cout << count << endl;
	sort(ss, ss + count+1, cmp);

	for (int i = 0; i < count + 1; i++)
	{
		for (int j = 0; j < ss[i].y;j++)
			cout << ss[i].x;

	}
	cout << endl;
		
	//while(1);
	return 0;
}
