/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/
/*
一般的加法分三步走，第一步不考虑进位加，第二步算进位，第三步是前两步相加；现在是异或和与运算来模拟前两步，没进位就不用有第三步了
*/

class Solution {
public:
    int Add(int num1, int num2)
    {
        while(1)
        {
            int temp=num1^num2;  //模拟不考虑进位
            int temp1=(num1&num2)<<1;  //算出进位
            
            if(temp1!=0)
            {
                num1=temp;
                num2=temp1;
            }
            else
                break;
        }
        return num1^num2;
        
    }
};
