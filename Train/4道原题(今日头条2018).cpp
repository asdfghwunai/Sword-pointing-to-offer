//最长无重复字符串---哈希
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;

map<char, int> mp;
int main()
{
	
	string ss;
	cin >> ss;

	for (int i = 0; i<ss.size(); i++)
		mp[ss[i]] = -1;

	int max_count = 0;
	int pre = -1;
	for (int i = 0; i < ss.size(); i++)
	{
		pre = max(pre, mp[ss[i]]);    //前面的最大的位置
		max_count = max(max_count, i - pre);
		mp[ss[i]] = i;
	}

	cout << max_count << endl;

	while (1);
	return 0;
}

//abcabcbb
//bbbbb
//abcabcabc



//===============================================
/*
#include <iostream>

using namespace std;
int M;
int num = 0;
int Q = 0;

void digui(int G[][1001], int i, int j, int &Max) 
{
	if (i < 0 || i >= M || j < 0 || j >= M)
		return;
	if (G[i][j] == 1) 
	{
		G[i][j] = 0; 
		
		digui(G, i - 1, j, Max); 
		digui(G, i + 1, j, Max);
		digui(G, i, j - 1, Max);
		digui(G, i, j + 1, Max);

	}
}

int G[1001][1001];
int main()
{

	cin >> M;
	
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> G[i][j];
	}
			
	for (int i = 0; i < M; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (G[i][j] == 1) 
			{
				int Max = 0; 
				num++;
				digui(G, i, j, Max);
				if (Max > Q) 
					Q = Max;
			}
		}
	}
	cout << num << endl;
	

	return 0;
}


*/



//图分团队---图的dfs

#include <iostream>

using namespace std;
int M;
int num = 0;


void digui(int G[][1001], int i, int j)
{
	if (i < 0 || i >= M || j < 0 || j >= M)
		return;
	if (G[i][j] == 1)
	{
		G[i][j] = 0;

		digui(G, i - 1, j);
		digui(G, i + 1, j);
		digui(G, i, j - 1);
		digui(G, i, j + 1);

	}
}

int G[1001][1001];
int main()
{

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> G[i][j];
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (G[i][j] == 1)
			{
				int Max = 0;
				num++;
				digui(G, i, j);
				
			}
		}
	}
	cout << num << endl;


	return 0;
}



//===============================================
//复原IP地址
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void search(string s, int start, int step, string ip, int& result)
{
	if (s.size() - start >(4 - step) * 3) //最长12位
		return;
	if (s.size() - start < (4 - step))  //最短4位
		return;

	if (start == s.size() && step == 4)  //step是分了多少段
	{
		ip.resize(ip.size() - 1);
		++result;
		return;
	}
	int num = 0;
	for (int i = start; i<start + 3; i++)
	{
		num = num * 10 + (s[i] - '0');
		if (num < 255)
		{
			ip += s[i];
			search(s, i + 1, step + 1, ip + '.', result);
		}
		if (num == 0) 
			break;
	}
}

int func(string s)
{
	int result=0;
	string ip;
	search(s, 0, 0, ip, result);
	return result;
}

int main() 
{
	string str;
	while (cin >> str)
	{
		cout << func(str) << endl;
	}
	return 0;
}

*/

//判断一个无.数字字符串可以划分成IP的数量---递归
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void search(string s, int start, int step, int& result)
{
	if (s.size() - start >(4 - step) * 3) //最长12位
		return;
	if (s.size() - start < (4 - step))  //最短4位
		return;

	if (start == s.size() && step == 4)  //step是分了多少段
	{
		
		++result;  //成功了
		return;
	}
	int num = 0;
	for (int i = start; i<start + 3; i++)
	{
		num = num * 10 + (s[i] - '0');
		if (num < 255)
		{
			
			search(s, i + 1, step + 1, result);
		}
		if (num == 0)
			break;
	}
}

int func(string s)
{
	int result=0;
	search(s, 0, 0, result);
	return result;
}

int main()
{
	string ss;
	int res = 0;
	cin >> ss;
	search(ss, 0, 0, res);
	
	cout << res << endl;

	while (1);
	return 0;
}


//============================
//查看是否是unicode码

#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& vec)
{
	int cc = 0;
	for (int num : vec){
		if (cc == 0){
			if ((num & 0x80) == 0){
				cc = 0;
			}
			else if ((num & 0xe0) == 0xc0){
				cc = 1;
			}
			else if ((num & 0xf0) == 0xe0){
				cc = 2;
			}
			else if ((num & 0xf8) == 0xf0){
				cc = 3;
			}
			else {
				return 0;
			}
		}
		else {
			if ((num & 0xc0) != 0x80) return 0;
			cc--;
		}
	}
	return cc == 0;
}

int main()
{
	int n, t;
	vector<int> v;
	cin >> n;
	
	v.assign(n, 0);
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
	}
	cout << func(v) << endl;
	
	while (1);
	return 0;
}

