/*
首先count得用long long 才行
其次，加count时别加错长度了
最后返回时你要再除以100000007才行，因为你count+=(mid-1-i+1)%1000000007会最后溢出的
*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        //int count=0;
        long long int count=0;
        if(data.size()<2)
            return 0;
        int low=0;
        int high=data.size()-1;
        vector<int> temp(data.size(),0);
        merge(data,low,high,temp,count);    //temp做中间数组
        //return count;   
        return count%1000000007;    //这里必须再除以10000000007才行
    }
    
    void merge(vector<int> &data,int low,int high,vector<int> &temp,long long int &count)
    {
        if(low==high)      //一样就不做
            return;
        int mid=(low+high)/2;
        merge(data,low,mid,temp,count);
        merge(data,mid+1,high,temp,count);
        merge_sort(data,low,mid+1,high,temp,count);    //合并中统计
    }
    
    void merge_sort(vector<int> &data,int low,int mid,int high,vector<int> &temp,long long int &count)
    {
        int i=low;
        int j=mid;    //各起点
        int k=low;
        while(i<mid&&j<=high)  //终点有high的
        {
            if(data[i]<=data[j])
                temp[k++]=data[i++];
            else           //data[i]>data[j]  说明有逆序
            {
                temp[k++]=data[j++];
                //count+=mid-1-low+1;     //mid-1是前半段的终点  我写错了low这里
                count+=(mid-1-i+1)%1000000007;
            }
        }
        while(i<mid)
        {
            temp[k++]=data[i++];
        }
        while(j<=high)
        {
            temp[k++]=data[j++];
        }
        for(int i=low;i<=high;i++)
        {
            data[i]=temp[i];
        }
    }
};
