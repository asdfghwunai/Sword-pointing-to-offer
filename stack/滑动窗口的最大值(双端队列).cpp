/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

/*
方法是先从头3个数建立初始queue（里面有个取最大数范例，保证前面大于后面新入的），后面一个个遍历其他的数(循环次数是你想要的)
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        deque<int> dq;
        if(num.size()<=0 || num.size()<size ||size<=0) 
            return result;
        
        for(int i=0;i<size;i++)
        {
            while(!dq.empty()&&num[i]>=num[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        
        for(int i=size;i<num.size();i++)
        {
            result.push_back(num[dq.front()]);
            
            while(!dq.empty()&&num[i]>=num[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(!dq.empty()&&i-dq.front()>=size)
                dq.pop_front();
 
        }
        result.push_back(num[dq.front()]);
        
        return result;
    }
};
