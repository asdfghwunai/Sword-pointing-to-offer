/*
 小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，
 请问他第一天最多能吃多少块巧克力
输入描述:

每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。



输出描述:

输出一个数表示小Q第一天最多能吃多少块巧克力。


输入例子1:

3 7


输出例子1:

4


*/

/*
看了半天也没咋看懂解法啊
*/

#include<iostream>
#include<math.h>
using namespace std;

int sum(int x)     //其实1 1 1都直接能满足情况，不过不是最大的
{
    int sum=0,t=0;
    while(x>1)     //这里=1不行啊     猜想：如果等于1说明你自认为最后一天吃的一定是1，太固定了
    {
        sum+=x;
        x=ceil((double)x/2);     //下一次至少是现在的数量减半
        t++;
    }
    return sum-t;
}

int main()
{
    int m,n;
    cin>>m>>n;
    if (m==1)
    {
        cout<<n<<endl;
        return 0;
    }
        
    int i=n,j=1;
    //int mid=ceil((double)(i+j)/2);
    while(i>j+1)     //i是情况上界，j是下界
    {
        
        int mid=ceil((double)(i+j)/2);
        
        int count=sum(mid);
        
        if(m+count==n)
        {
            cout<<mid<<endl;
            return 0;
        }
        else if(m+count<n)    //说明count还有上升空间
            j=mid;
        else         //说明count太大
            i=mid;
         
        
        /*
        if(m+count<=n)
        {
            j=mid;
        }
        else
            i=mid;
        mid=ceil((double)(i+j)/2);
        */
    }
    cout<<j<<endl;
    return 0;
}
