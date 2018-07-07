/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

/*---方法----
幂要分正负数，为负时底不能为0，为正时说0的0次方无意义，返回0或1都行

*/


class Solution {
public:
    double Power(double base, int exponent) {
        bool flag=0;
        
        if(exponent<0)
        {
           exponent=-exponent;
            flag=1; 
        }
        if(flag==0)
        {
            double result=1.0;
            for(int i=0;i<exponent;i++)
                result=result*base;
            return result;
        }
        else
        {
            //if(base==0)    //不能计算,我这样写虽然能通过但不对
            if(base<1e-7&&base>-1e-7) 
                return -1;
            else
            {
                double result=1.0;
                for(int i=0;i<exponent;i++)
                    result=result*base;
                return 1.0/result;
            }
        }
            
    }
};
