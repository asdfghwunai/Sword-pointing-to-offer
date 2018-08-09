/*
小明是幼儿园的一名老师。某天幼儿园园长给小朋友们每人发一颗糖果，小朋友们拿到后发现有一些同学拿到的糖果颜色和自己相同，有一些同学糖果颜色和自己不同。
假定每个小朋友只知道有多少同学和自己拿到了相同颜色的糖果。
上课后，有一部分小朋友兴奋的把这一结果告诉小明老师，并让小明老师猜一猜，最少有多少同学拿到了糖果。
例如有三个小朋友告诉小明老师这一结果如下：
其中第一个小朋友发现有1人和自己糖果颜色一样，第二个小朋友也发现有1人和自己糖果颜色一样，第三个小朋友发现有3人和自己糖果颜色一样。
第一二个小朋友可互相认为对方和自己颜色相同，比如红色；
第三个小朋友不可能再为红色（否则第一二个小朋友会发现有2人和自己糖果颜色相同），假设他拿到的为蓝色糖果，那么至少还有另外3位同学拿到蓝色的糖果，最终至少有6位小朋友拿到了糖果。
现在请你帮助小明老师解答下这个谜题。

*/

//---错误解法
/*
只想着1 1 3这种过于简单的情况，或 2 2 3 或 0 0 0，多考虑 一个 2 2 2 3就行了。
 2 2 3和2 2 2 3是一种情况的，都要实际3个2才行。。。 
*/
#include<iostream>
#include<unordered_map>
using namespace std;
  
int main()
{
    int x;
    unordered_map<int,int> suoyin;
    while(scanf("%d",&x)!=EOF)
    {
        (suoyin[x])++;
    }
    int count=0;
    for(auto iter=suoyin.begin();iter!=suoyin.end();iter++)
    {
        if(iter->first==0)
            count+=iter->second;   //直接加0的数量
        else
        {
            if(iter->second==1)
                count=iter->first+1;
            else
                count=iter->first+1;
        }
    }
    cout<<count<<endl;
    return 0;
}


