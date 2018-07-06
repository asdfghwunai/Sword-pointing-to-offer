/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

/*----方法----
注意操作前先把int转为unsigned int,因为对int负数移位和你想的不太一样，说什么最后会变成0xFFFFFFFF

注意int转为unsigned int还是它在计算机的样子

*/

class Solution {
public:
     int  NumberOf1(int n) {
         int result=0;
         unsigned int number=n;
         while(number!=0)
         {
             result+=number&1;
             number=number>>1;
         }
         return result;
     }
};
