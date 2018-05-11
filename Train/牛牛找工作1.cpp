/*
60%

*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;


bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first<b.first;
}


int main()
{
	
	multimap <int, int> m;
	int task_num = 0, people_num = 0;
	int nandu, gongzi,people_nandu;
	vector<pair<int,int>> people;   //难度和id
	

	    cin >> task_num >> people_num;

		vector<int> result(people_num);
	
		m.clear();
		people.clear();
		for (int i = 0; i < task_num; i++)  //输入任务难度和工资
		{
			cin >> nandu >> gongzi;
			//	m[nandu] = gongzi;
			m.insert(pair<int, int>(nandu, gongzi));
		}

		for (int i = 0; i < people_num; i++)
		{
			cin >> people_nandu;
			people.push_back(pair<int,int>(people_nandu,i));   //输入每个人容忍的难度
		}

		sort(people.begin(), people.end(),comp);   //把人物排序，到时可以接着在后面找更好的

		auto iter_zhongdian = m.begin();
		//找iter终点
		auto iter = m.begin();
		int max = 0; 
		for (int i = 0; i < people.size(); i++)
		{
			
			
			for (; iter != m.end();)   //笨方法---依次遍历
			{
				
				if (people[i].first >= iter->first)  //先前进再后退
				{
					if (iter->second > max)
					{
						max = iter->second;
					}
					iter++;
				}
					
				else
				{


					iter_zhongdian = --iter;

					break;
				}
			}
			if (iter == m.end())  //
			{
				iter_zhongdian = --iter;
			}
			result[people[i].second] = max;
			

			/*
			//找从头到遍历终点的最大值
			iter_zhongdian++;
			int max = 0;
			for (auto iter = m.begin(); iter != iter_zhongdian; iter++)
			{
				if (iter->second > max)
					max = iter->second;

			}
			cout << max << endl;
			*/
		}

		for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;

		return 0;



} 
