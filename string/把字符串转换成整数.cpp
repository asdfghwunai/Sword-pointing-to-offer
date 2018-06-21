/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0

示例1
输入
+2147483647
    1a33
输出
2147483647
    0
*/

/*
一定要用long long保存结果，先跳空格，再判断符号，再在里面做加减(得判断溢出)
*/

class Solution {
public:
    int StrToInt(string str) {
        int invalid=0;  //非法输入标志
        bool minus=0;    //负数标志
        long long num=0;
        if(str.size()==0)
        {
            invalid=1;
            return 0;
        }
            
        
        auto iter=str.begin();
        while(iter!=str.end())
        {
            while(*iter==' ')
                iter++;
            if(*iter=='-')
            {
                minus=1;
                iter++;
            }
            else if(*iter=='+')
            {
                minus=0;
                iter++;
            }
            if(iter==str.end())  //去除符号直接结束了也是非法
            {
                invalid=1;
                return 0;
            }
            while(iter!=str.end()&&(*iter)>='0'&&(*iter)<='9')
            {
                num=num*10+(*iter)-'0';
                if(minus&&num<INT_MIN)     //溢出
                {
                    invalid=1;
                    return 0;
                }
                else if(minus==0&&num>INT_MAX)
                {
                    invalid=1;
                    return 0;
                }
                iter++;
            }
            if(iter==str.end())  //圆满结束
            {
                invalid=0;  //可以不写
            }
            else
            {
                num=0;
                invalid=1;
                return num;
            }
                
        }
        if(minus==1)
            return -num;
        else
            return num;
    }
};
