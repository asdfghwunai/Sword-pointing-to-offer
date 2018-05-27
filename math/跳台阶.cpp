/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*---方法--
递归确实太慢了，几百毫秒，重复计算问题太严重了，而迭代几ms
*/

/*
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
*/

class Solution {
public:
    int jumpFloor(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        int a=1;
        int b=2;
        int c;
        for(int i=3;i<=number;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
