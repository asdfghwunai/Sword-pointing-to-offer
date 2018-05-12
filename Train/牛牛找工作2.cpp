/*
相比1进一步改进----把map建立换成了类，然后采用快排

出现了一个错误：work task[10000];  //原因是数组开辟太小，数组越界，开辟成1000000了
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



class work{
public:
	int nandu;
	int gongzi;
	work(){}
	
};

bool comp_task(const work &a,const work &b)
{
    if(a.nandu==b.nandu)
        return a.gongzi>b.gongzi;
	return a.nandu < b.nandu;
}

work task[1000000];
int main()
{
	
	
	int task_num = 0, people_num = 0;
	int nandu, gongzi,people_nandu;
	vector<pair<int,int>> people;   //难度和id
	

	    cin >> task_num >> people_num;

		vector<int> result(people_num);
	
		people.clear();
		for (int i = 0; i < task_num; i++)  //输入任务难度和工资
		{
			cin >> nandu >> gongzi;
		
			task[i].nandu = nandu;
			task[i].gongzi = gongzi;
		}

		for (int i = 0; i < people_num; i++)
		{
			cin >> people_nandu;
			people.push_back(pair<int,int>(people_nandu,i));   //输入每个人容忍的难度
		}

		sort(task,task+task_num,comp_task);
		sort(people.begin(), people.end(),comp);   //把人物排序，到时可以接着在后面找更好的

		
		int max = 0; 
		int k = 0;
		for (int i = 0; i < people.size(); i++)
		{
			
			
			for (; k<task_num;)   //笨方法---依次遍历
			{
				
				if (people[i].first >= task[k].nandu)  //先前进再后退
				{
					if (task[k].gongzi > max)
					{
						max = task[k].gongzi;
					}
					k++;
				}
					
				else
				{

					break;
				}
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
