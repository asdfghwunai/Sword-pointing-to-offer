/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
*/

/*
这种题有点巧妙，方法就是找个终点，根据一个规则加左右边界
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int zhongdian=(sum+1)/2;  //以3为例，终点是1
        int small=1;
        int big=2;
        vector<int> temp;
        vector<vector<int>> result;
        
        while(small<zhongdian)
        {
            int cursum=0;
            temp.clear();
            for(int i=small;i<=big;i++)  //求和
            {
                cursum+=i;
                temp.push_back(i);
            }
                
            if(cursum==sum)
            {
                result.push_back(temp);
                big++;   //让当前不满足
            }
                
            else if(cursum<sum)  //像这种情况是还没超过sum时，一点点扩大后面的
                big++;
            else           //这种情况是不小心阔的太大了，这种东西不能原路返回
                small++;
        }
        return result;
    }
};
