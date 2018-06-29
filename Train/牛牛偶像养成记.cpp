


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
