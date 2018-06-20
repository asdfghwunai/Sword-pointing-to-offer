/*
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

/*
一个个判断法直接超时，没办法了
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    
        if(index<=0)
            return 0;
        int num=0;
        int start=0;
        while(num<index)
        {
            start++;
            int check=start;
            while(check%2==0)
                check=check/2;
            while(check%3==0)
                check=check/3;
            while(check%5==0)
                check=check/5;
            if(check==1)
                num+=1;
        }
        return start;
    }
};

/*
没办法，只能看人家了，很像斐波那契数列的从前到后递推法。这种方法都是技巧性方法，没啥普适性啊
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    
        if(index<=0)
           return 0;
        vector<int> result(index);
        result[0]=1;
        int t2=0,t3=0,t5=0;
        for(int i=1;i<index;i++)
        {
            result[i]=min(result[t2]*2,min(result[t3]*3,result[t5]*5));
            if(result[t2]*2==result[i])
                t2++;
            if(result[t3]*3==result[i])
                t3++;
            if(result[t5]*5==result[i])
                t5++;
        }
        return result[index-1];
     }
};
