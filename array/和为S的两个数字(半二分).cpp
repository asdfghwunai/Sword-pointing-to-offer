/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

/*
只要和排序有点关系，就要想到用二分那种模式
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size()==0)
            return result;
        int first=0;
        int last=array.size()-1;
        while(first<last)
        {
            int cursum=array[first]+array[last];
            if(cursum==sum)
            {
                result.push_back(array[first]);
                result.push_back(array[last]);
                return result;
            }
            else if(cursum<sum)
                first++;
            else
                last--;
        }
        return result;
            
    }
};
