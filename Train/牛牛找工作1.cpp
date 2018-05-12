/*
原版30%
1.建multimap
2.然后找满足难度要求终点
3.再从头遍历到找到的终点来找工资最大的数

改进一点 40%
把2和3合并在找满足难度要求终点的过程中找最大工资

改进一点60%
把人物难度排序，到时下个人可以在上个人的难度终点处开始找

然后就不行了，推测是建红黑树有点慢

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
		auto iter = m.begin();                //被改进的地方2
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
			//找从头到遍历终点的最大值     //被改进的地方1
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
