/*

牛牛很喜欢对数字进行比较，但是对于3 > 2这种非常睿智的比较不感兴趣。上了高中之后，学习了数字的幂，他十分喜欢这种数字表示方法，比如xy。

由此，他想出了一种十分奇妙的数字比较方法，给出两个数字x和y，请你比较xy和yx的大小，如果前者大于后者，输出">"，小于则输出"<"，等于则输出"="。

输入描述:

两个数字x和y。

满足1 <= x,y <= 109



输出描述:

一个字符，">"，"<"或者"="。


输入例子1:

2 2


输出例子1:

=


输入例子2:

2 4


输出例子2:

=
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    double f1=1.0*y*log2((double)x);
    double f2=1.0*x*log2((double)y);
    if(fabs(f1-f2)<1e-6)   //这有问题，abs里是int
        cout<<"="<<endl;
    else if(f1>f2)
        cout<<">"<<endl;
    else
        cout<<"<"<<endl;
    return 0;
}
