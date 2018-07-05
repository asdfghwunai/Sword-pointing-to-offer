/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

*/

/*
插入时排序用快排或直接建堆
*/

class Solution {
public:
    void Insert(int num)
    {
        data.push_back(num);
        sort(data.begin(),data.end());
    }

    double GetMedian()
    { 
        int size=data.size();
        if(size&1)
            return static_cast<double>(data[size>>1]);
        else
        {
            double left=static_cast<double>(data[size>>1]);
            double right=static_cast<double>(data[(size>>1)-1]);
            return (left+right)/2;
        }
            
    }
    
    vector<int> data;
};
