/*


小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
对于一个任务,它只能交由一台机器来完成, 如果安排给它的机器的最长工作时间小于任务需要的时间, 则不能完成,如果完成这个任务将获得200 * xi + 3 * yi收益。

对于一台机器,它一天只能完成一个任务, 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。

小Q想在今天尽可能的去完成任务, 即完成的任务数量最大。如果有多种安排方案,小Q还想找到收益最大的那个方案。小Q需要你来帮助他计算一下。

输入描述:

输入包括N + M + 1行,
输入的第一行为两个正整数n和m(1 <= n, m <= 100000), 表示机器的数量和任务的数量。
接下来n行,每行两个整数zi和wi(0 < zi < 1000, 0 <= wi <= 100), 表示每台机器的最大工作时间和机器等级。
接下来的m行,每行两个整数xi和yi(0 < xi < 1000, 0 <= yi<= 100), 表示每个任务需要的完成时间和任务的难度等级。



输出描述:

输出两个整数, 分别表示最大能完成的任务数量和获取的收益。


输入例子1:

1 2
100 3
100 2
100 1


输出例子1:

1 20006


*/


#include<iostream>
#include<algorithm>
using namespace std;

struct Machine
{
    public:
    int time;
    int level;
    Machine()
    {
    }
}machine[10000];

struct Task
{
    int time;
    int level;
    Task()
    {
    }
}task[10000];

bool cmp_machine(const Machine &A,const Machine &B)
{
    if(A.time!=B.time)
        return A.time>B.time;
    else
        return A.level>B.level;
}

bool cmp_task(const Task &A,const Task &B)  //由大到小解决任务，所以机器也得由大到小
{
    if(A.time!=B.time)
        return A.time>B.time;
    else
        return A.level>B.level;
}

int main()
{
    int machine_num,task_num;
    cin>>machine_num>>task_num;
    int x,y;
    for(int i=0;i<machine_num;i++)
    {
        cin>>x>>y;
        machine[i].time=x;
        machine[i].level=y;
    }
    for(int i=0;i<task_num;i++)
    {
        cin>>x>>y;
        task[i].time=x;
        task[i].level=y;
    }
    sort(task,task+task_num,cmp_task);
    sort(machine,machine+machine_num,cmp_machine);
    
    int count=0;
    int sum=0;
    int j=0;
    for(int i=0;i<task_num;i++)
    {
        for(;j<machine_num;)
        {
            if(machine[j].time>=task[i].time)
            {
                if(machine[j].level>=task[i].level)
                {
                    count++;
                    sum=200*task[i].time+3*task[i].level;
                    j++;
                    break;
                }
                else break;
            }
            else
                break;
        }
    }
    cout<<count<<" "<<sum<<endl;
    
    return 0;
}
