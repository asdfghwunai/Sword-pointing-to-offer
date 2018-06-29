/*
链接：https://www.nowcoder.com/questionTerminal/39d32d34e18240d4b62b203c8c1d53ee?toCommentId=1451035
来源：牛客网

为了拯救因入学人数骤降，面临废弃的学校，牛牛决定成为偶像啦。当然，作为一个偶像，肯定是要上台表演的。
已知牛牛拿到了n个上台表演的机会，第i次表演的上台时间为ti时刻，需要表演mi这么长的时间。
牛牛为了提高自己的知名度，肯定要取得最多的上场次数。请问，牛牛最多能上场多少次呢？

输入描述:

第一行输入一个数字n(1≤n≤100000)，表示牛牛获得的上台表演的机会
接下来n行，每行输入两个数字ti(1≤ti≤108)和mi(1≤mi≤108), 表示第i次表演机会的上台时间和该次表演需要的总时间（表演途中不能中断表演退出）。



输出描述:

牛牛最多能上场的次数。

示例1
输入

3
1 2
3 2
5 2

输出

3
*/

//----当成数飞机了，其实是贪心

#include<iostream>
#include<vector>
#include<set>
#include<map>
 
using namespace std;
class airplane{
 
public:
    int start = 0;
    int end = 0;
    airplane(int x,int y)
    {
        start = x;
        end = x + y;
    }
     
};
 
int shufeiji(vector<airplane> &airs)
{
     
 
    set<int> time;
    map<int, int> count;
    for (auto iter = airs.begin(); iter != airs.end(); iter++)
    {
        ++count[iter->start];  //记住直接能用就行
        --count[iter->end];
 
        time.insert(iter->start);
        time.insert(iter->end);
    }
 
    int max = 0, jishu = 0;
    for (auto iter = time.begin(); iter != time.end(); iter++)
    {
        jishu += count[*iter];
        if (jishu > max)
            max = jishu;
    }
    return max;
     
}
 
int main()
{
    int num;
    cin >> num;
    int qishi, chixu;
 
    vector<airplane> airs;
    for (int i = 0; i < num; i++)
    {
        cin >> qishi >> chixu;
        airplane air =airplane(qishi, chixu);
        airs.push_back(air);
    }
 
    int count=shufeiji(airs);
 
    return 0;
}

//-------贪心做法，先根据结束时间排序（结束时间一样就开始时间越早越好），然后选择不冲突的就行

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;
class airplane{

public:
	int start = 0;
	int end = 0;
	airplane(int x,int y)
	{
		start = x;
		end = x + y;
	}
	
};

bool cmp(const airplane& A, const airplane& B)
{
	if (A.end != B.end)
		return A.end < B.end;
	else
		return A.start < B.start;
}

int main()
{
	int num;
	cin >> num;
	int qishi, chixu;

	vector<airplane> airs;
	for (int i = 0; i < num; i++)
	{
		cin >> qishi >> chixu;
		airplane air =airplane(qishi, chixu);
		airs.push_back(air);
	}
	sort(airs.begin(),airs.end(),cmp);
	int t = 0,count=0;
	for (auto iter = airs.begin(); iter != airs.end(); iter++)
	{
		if (t <= iter->start)   //上次结尾的在这次开始之前
		{
			count++;
			t = iter->end;
		}
			

	}
	cout << count << endl;
	return 0;
}
