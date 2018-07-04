/*


时间限制：1秒

空间限制：32768K
小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。每门课由平时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai ,若想让这门课的考试成绩多拿一分的话，小v要花bi 的时间复习，不复习的话当然就是0分。同时我们显然可以发现复习得再多也不会拿到超过满分的分数。为了拿到奖学金，小v至少要花多少时间复习。

输入描述:

第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1



输出描述:

一行输出答案。


输入例子1:

5 10 9
0 5
9 1
8 1
0 1
9 100


输出例子1:

43


*/

/*=====================
60%通过率，有点完蛋啊

====================*/
//贪心。确定了 先拿最值钱的课，就是时间最小的，每门课上限是10分，总分是45分
/*--记录下思路吧
我感觉得把每门课存个节点，然后一个一个节点的遍历

*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1e5;
struct node
{
    int x,y;
    //用默认构造函数吧
};
node ke[maxn];
int n,r,avg;

bool cmp(const node &A,const node &B)
{
    if(A.y!=B.y)
        return A.y<B.y;    //时间代价越小放前面
    else
        return A.x<B.x;     //把剩余分最多的放前面
}

int main()
{
    while(cin>>n>>r>>avg)
    {
        
    
    int ai,bi;
    long long total=avg*n;     //需求
   long long count=0;      //达到
    long long t=0;
    for(int i=0;i<n;i++)
    {
        cin>>ai>>bi;
        ke[i].x=ai;
        ke[i].y=bi;
        count+=ai;
    }
    if(count>=total)   //直接满足要求
    {
        cout<<t<<endl;
        return 0;
    }
    
    sort(ke,ke+n,cmp);
    
    for(int i=0;i<n;i++)
    {
        while(ke[i].x<r)   //有点繁琐
        {
            count++;
            (ke[i].x) ++;
            t+=ke[i].y;
            if(count==total)
                break;
        }
        if(count==total)
                break;
    }
    cout<<t<<endl;
    }
    
    
    return 0;
}

/*=======================
优化俩地方还是那样子
=============================*/

//贪心。确定了 先拿最值钱的课，就是时间最小的，每门课上限是10分，总分是45分
/*--记录下思路吧
我感觉得把每门课存个节点，然后一个一个节点的遍历

*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e6;
struct node
{
	int x, y;
	//用默认构造函数吧
};

int n, r, avg;
node ke[maxn];

bool cmp(const node &A, const node &B)
{
	if (A.y != B.y)
		return A.y<B.y;    //时间代价越小放前面
	else
		return A.x<B.x;     //把剩余分最多的放前面
}

int main()
{
	while (cin >> n >> r >> avg)
	{

        
		int ai, bi;
		int total = avg*n;     //需求
		int count = 0;      //达到
		long  t = 0;
		for (int i = 0; i<n; i++)
		{
			cin >> ai >> bi;
			ke[i].x = ai;
			ke[i].y = bi;
			count += ai;
		}
		if (count >= total)   //直接满足要求
		{
			cout << t << endl;
			return 0;
		}

		sort(ke, ke + n, cmp);

		for (int i = 0; i<n; i++)
		{
			if (count + (r - ke[i].x)<total)     //直接加
			{
				count = count + r - ke[i].x;
				
				/*                       //这个错误这是醉了
				ke[i].x = r;
				t += (r - ke[i].x)*ke[i].y;
				*/
				t += (r - ke[i].x)*ke[i].y;
				ke[i].x = r;
				
			}
			else
			{
                /*
				while (ke[i].x<r)   //有点繁琐
				{
					count++;
					(ke[i].x)++;
					t += ke[i].y;
					if (count == total)
						break;
				}
                */
                t+=(total-count)*ke[i].y;
                break;
			}

			//if (count == total)  //和里面那个while同生共死
			//	break;
		}
		cout << t << endl;
	}

	return 0;
}

/*=========
真正的问题来自while循环处理多个用例不能有return 啊
================*/

//贪心。确定了 先拿最值钱的课，就是时间最小的，每门课上限是10分，总分是45分
/*--记录下思路吧
我感觉得把每门课存个节点，然后一个一个节点的遍历

*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e6;
struct node
{
	int x, y;
	//用默认构造函数吧
};

int n, r, avg;
node ke[maxn];

bool cmp(const node &A, const node &B)
{
	if (A.y != B.y)
		return A.y<B.y;    //时间代价越小放前面
	else
		return A.x<B.x;     //把剩余分最多的放前面
}

int main()
{
	while (cin >> n >> r >> avg)
	{


		int ai, bi;
		int total = avg*n;     //需求
		int count = 0;      //达到
		long  t = 0;
		for (int i = 0; i<n; i++)
		{
			cin >> ai >> bi;
			ke[i].x = ai;
			ke[i].y = bi;
			count += ai;
		}
		if (count >= total)   //直接满足要求
		{
			cout << 0 << endl;
			//return 0;    //我能说啥呢，败就败在循环输入不能有return
		}
		else
		{
			sort(ke, ke + n, cmp);

			for (int i = 0; i<n; i++)
			{
				if (count + (r - ke[i].x)<total)     //直接加
				{
					count = count + r - ke[i].x;

					/*                       //这个错误这是醉了
					ke[i].x = r;
					t += (r - ke[i].x)*ke[i].y;
					*/
					t += (r - ke[i].x)*ke[i].y;
					ke[i].x = r;

				}
				else
				{
					/*
					while (ke[i].x<r)   //有点繁琐
					{
					count++;
					(ke[i].x)++;
					t += ke[i].y;
					if (count == total)
					break;
					}
					*/
					t += (total - count)*ke[i].y;
					break;
				}

				//if (count == total)  //和里面那个while同生共死
				//	break;
			}
			cout << t << endl;
		}

		
	}

	return 0;
}
    
