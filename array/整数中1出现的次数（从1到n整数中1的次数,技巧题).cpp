/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/
/*
虽然有巧妙的方法，但那方法我不用了，不具有普适性，我就还用笨方法写出来算了
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int num=0;
        for(int i=n;i>=1;i--)
        {
            int k=geshu(i);  //看一个数的，以后可以把一样的东西设成函数
            num+=k;
        }
        return num;
    }
    
    int geshu(int n)
    {
        int k=0;
        while(n>=10)
        {
            int wei=(n%10==1)?1:0;
            k+=wei;
            n=n/10;
        }
        if(n==1)
            k+=1;
        return k;
    }
};
