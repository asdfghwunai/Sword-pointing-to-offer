/*
链接：https://www.nowcoder.com/questionTerminal/62cdf520b9d94616b6644ac03a0306ff
来源：牛客网

一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai ，每盏灯可以覆盖到的最远距离为d，为了照明需求，所有灯的灯光必须覆盖整条街，但是为了省电，要是这个d最小，请找到这个最小的d。

输入描述:

每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。第二行有n个整数(均大于等于0小于等于l)，为每盏灯的坐标，多个路灯可以在同一点。



输出描述:

输出答案，保留两位小数。

示例1
输入

7 15
15 5 3 7 9 14 0

输出

2.50
*/

/*
就是算出俩路灯之间的距离存起来，最后排序，中间得除以2，两头不用除
自己随便写的，傻了，直接内存爆了，居然直接存街道数组来算距离，大方向错了  我还想用bitmap来存这个大数组，但是不会搞，越想越麻烦
*/

#include<iostream>
#include<string.h>
#include<set>
#include<vector>
using namespace std;
 
const int maxn = 1000000;
char jiedao[maxn];
//set<int> s;
int n, l;
int x;
vector<double> res;
 
int main()
{
    memset(jiedao,0,sizeof(jiedao));
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> x;   //路灯坐标可以重复的
        jiedao[x] = 1;
 
    }
 
    int last = 0;
        
    for (int i = 0; i <= l; i++)
    {
        if (res.empty())
        {
            if (jiedao[i] == 1)
            {
                res.push_back(i-last);   //压入第一个
                last = i;
            }
        }
        else
        {
            if (jiedao[i] == 1)
            {
                double temp = (double)(i - last)/2;
                res.push_back(temp);
                last = i;
            }
        }
    }
    res.push_back(l-last);  //压入最后一个
 
    /*
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i]<<endl;
    }
    */
    double max = res[0];
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i]>max)
            max = res[i];
    }
    printf("%.2lf\n",max);
    //while (1);
 
    return 0;
}




/*=============================
换种思路，把直接路灯坐标存储，也不用去重其实，我还想到用set去下重

===============================*/

#include<iostream>
#include<string.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1005;
int ludeng[maxn];
//set<int> s;
int n, l;
int x;


int main()
{
	
	while(cin >> n >> l)
	{
		memset(ludeng, 0, sizeof(ludeng));
		vector<double> res;
		for (int i = 0; i < n; i++)
		{
			cin >> x;   //路灯坐标可以重复的
			ludeng[i] = x;

		}
		sort(ludeng, ludeng + n);      //直接排序，不用管一样的


		int last = 0;

		for (int i = 0; i <n; i++)
		{
			if (res.empty())
			{
				res.push_back(ludeng[i] - last);   //压入第一个
				last = ludeng[i];

			}
			else
			{
				double temp = (double)(ludeng[i] - last) / 2;
				res.push_back(temp);
				last = ludeng[i];

			}
		}
		res.push_back(l - ludeng[n - 1]);  //压入最后一个

		/*
		for (int i = 0; i < res.size(); i++)
		{
		cout << res[i]<<endl;
		}
		*/

		double max = res[0];
		for (int i = 0; i < res.size(); i++)
		{
			if (res[i]>max)
				max = res[i];
		}
		printf("%.2lf\n", max);
	}
	
	return 0;
}



