/*
写的不好，问题出在partirion那个k以为是相对low的，其实是相对0的
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k>input.size())
            return res;
        int low=0;
        int high=input.size()-1;
        findk(input,low,high,res,k-1);   //减1是从0开始
        return res;
    }
    
    void findk(vector<int>& input,int low,int high,vector<int>& res,int k)
    {
        
        if(low==high)   //结束了
        {
            //if(k==low)      //要不要都行，其实就差一步
            {
                for(int i=0;i<=k;i++)
                {
                    res.push_back(input[i]);
                }
                return;
            }
        }
        
       else if(low<high)
        {
            int index=partition(input,low,high);
            if(index<k)
                //findk(input,low+index,high,res,k-index);   //index是相对起点来说的，不是相对low
                findk(input,index+1,high,res,k);
            else if(index==k)    //直接找到了
            {
                for(int i=0;i<=k;i++)
                {
                    res.push_back(input[i]);
                    
                }
                return;
            }
            else
                //findk(input,low,low+index,res,k);
                findk(input,low,index-1,res,k);
        }
    }
    
    int partition(vector<int>& input,int low,int high)   //就当已经解决好partiton了
    {
        int key=input[low];
        while(low<high)
        {
            while(low<high && input[high]>=key)   //找到一个小于key的，应该移到左边
                high--;
            swap(input[low],input[high]);
            while(low<high && input[low]<=key)   //找到一个小于key的，应该移到右边
                low++;
            swap(input[low],input[high]);
        }
        return low;
    }
    
};
