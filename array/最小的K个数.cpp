/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,
*/

/*
法1：partition法，找第几大
法2：构造最大堆，然后一个一个判断，比最大大就丢弃，比最大小就移除最大然后插入
*/

class Solution {
public:
    int Partition(vector<int> &a,int low,int high)
    {
        int budong=a[low];
        while(low<high)
        {
            while(low<high&&a[high]>=budong)
                high--;
            a[low]=a[high];
            while(low<high&&a[low]<=budong)
                low++;
            a[high]=a[low];
        }
        a[low]=budong; 
        return low;
    }
     
    void findk(vector<int> &input,int low,int high,vector<int> &result,int k)
    {
        if(low<high)
        {
            int mid=Partition(input,low,high);
            if(mid==k-1)
            {
                for(int i=0;i<k;i++)
                    result.push_back(input[i]);
                return;    //提前结束
            }
            else if(mid>k-1)
            {
                findk(input,low,mid-1,result,k);
            }
            else{
                findk(input,mid+1,high,result,k);
            }
        }
        else if(low==high)
        {
            if(low==k-1)
            {
                for(int i=0;i<k;i++)
                    result.push_back(input[i]);
                return;    //提前结束
            }
        }
    }
      
      
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k>input.size())
            return result;
         
        int low=0;
        int high=input.size()-1;
        findk(input,low,high,result,k);
        return result;
    }
};
