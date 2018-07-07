/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。

n<=39
*/

//递归写着会超时，只能用迭代了

/*
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
*/

class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int a,b,c;
        for(int i=2;i<=n;i++)
        {
            if(i==2)  //开启
            {
                a=0;
                b=1;
                c=a+b;
                continue;
            }
            a=b;
            b=c;
            c=a+b;
        }
        return c;
    }
};


