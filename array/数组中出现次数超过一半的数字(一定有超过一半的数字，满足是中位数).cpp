/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
/*
法1：用partition法，找n/2大的
法2：用偏门的抵消法，维护两个数字，一个记录次数，一个记录数字，次数为0就记录下一个数
法3：就是我的hash——map法了，反正时间复杂度都是O(n)
*/


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int,vector<int>> m;
        
        for(int i=0;i<numbers.size();i++)
        {
            m[numbers[i]].push_back(numbers[i]);
        }
        
        int len=numbers.size();
        
        for(auto iter=m.begin();iter!=m.end();iter++)
        {
            if(iter->second.size()>len/2)
                return iter->first;
        }
        return 0;
    }
};
