/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*---方法----
里面有移位的思想
 找到一个偶数，看它右边如果存在奇数就要移位，不存在就直接结束
 
 那个offer有个用了快排partition的模子来做，就是维护俩指针来同时找到不满足条件的，然后交换，咋突然感觉这种交换可以用于快排？
 仔细想了想不行，快排分区要返回一个partition，这个交换只是让前后颠倒，不能找到那个分区

*/

//方法  找到一个偶数，看它右边如果存在奇数就要移位并且起点要不变(i--)，不存在就直接结束
class Solution {
public:
    void reOrderArray(vector<int> &array) {
       
        
        bool flag=1;   //大循环标志
        
        for(int i=0;i<array.size()&&flag;i++)
        {
           flag=1;
           if(array[i]%2==0)  //找到第一个偶数
           {
               int j;
               for(j=i+1;j<array.size();j++)
               {
                   if(array[j]%2==1) //后面有奇数
                   {
                       
                       int temp=array[i];
                       int k;
                       for(k=i;k<array.size()-1;k++)  //移位
                       {
                           array[k]=array[k+1];
                       }
                       array[k]=temp;
                       i--;   //移动完为确保漏检第一个要i--；
                       
                       break;
                   }
               }
               if (j == array.size())
                  flag = 0;   //后面没奇数了，下次不用走了
               
           }
        }
        
    }
};
