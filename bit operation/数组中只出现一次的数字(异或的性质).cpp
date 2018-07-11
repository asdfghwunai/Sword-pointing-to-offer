/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

/*
经过异或后反正俩目标可以分离开，至于其他小兵跟谁跑看造化了，但是一样的肯定会在一起，这不用担心
时间复杂度，先全体异或得O（n），然后找不一样的位，最后还得再遍历一遍也得O（n），加起来O（2n）至少
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int temp=0;
        for(int i=0;i<data.size();i++)
            temp^=data[i];
        int wei=find_first1(temp);  //找第一个1
        *num1=0,*num2=0;
        for(int i=0;i<data.size();i++)
        {
            if(isBit1(data[i],wei))
                *num1^=data[i];
            else
                *num2^=data[i];
        }
    }
    
    int find_first1(int src)
    {
        int wei=0;
        while(src)
        {
            if(src&1==1)
                break;
            wei++;
            src=src>>1;
        }
        return wei;
    }
    
    bool isBit1(int src,int wei)
    {
        for(int i=0;i<wei;i++)
            src=src>>1;
        if(src&1==1)
            return 1;
        else
            return 0;
    }
};
