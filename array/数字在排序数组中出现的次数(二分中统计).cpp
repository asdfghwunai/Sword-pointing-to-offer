/*
统计一个数字在排序数组中出现的次数。
*/

/*
二分查找变种题，不能先二分查找目标，再两边扩展找边缘，应该是在二分查找过程中就确定边缘，和那个用归并排序求数组的逆序对一个道理
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int number=0;
        int first=get_firstk(data,0,data.size()-1,k);
        int last=get_lastk(data,0,data.size()-1,k);
        if(first>-1&&last>-1)   //本来就是同时大于-1的
            number=last-first+1;
        return number;
    }
    
    int get_firstk(vector<int> &data,int first,int last,int k)   //二分查找变种
    {
        while(first<=last)
        {
            int mid=(first+last)/2;
            if(data[mid]==k)   //像左找
            {
                if((mid>0&&data[mid-1]<k)||(mid==0))    //正好找到,两种情况
                    return mid;
                else             //没那么巧就终点向左移
                    last=mid-1;
            }
            else if(data[mid]<k)  
                first=mid+1;
            else
                last=mid-1;
                
            
        }
        return -1;
    }
    
    int get_lastk(vector<int> &data,int first,int last,int k)   //二分查找变种
    {
        while(first<=last)
        {
            int mid=(first+last)/2;
            if(data[mid]==k)   //找到k了
            {
                if((mid<data.size()-1&&data[mid+1]>k)||(mid==data.size()-1))    //正好找到,两种情况
                    return mid;                                 //这里其实嵌入了一条路走到黑法
                else             //没那么巧就终点向左移
                    first=mid+1;
            }
            else if(data[mid]<k)  
                first=mid+1;
            else
                last=mid-1;
                
            
        }
        return -1;
    }
};
