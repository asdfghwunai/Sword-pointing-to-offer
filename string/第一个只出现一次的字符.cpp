/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/

/*
方法就是一般的哈希表
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size()==0)
            return -1;
        
        unordered_map<char,vector<int>> result;
        for(auto it=str.begin();it!=str.end();it++)
        {
            
            result[*it].push_back(it-str.begin());
        }
        /*
        for(auto it=result.begin();it!=result.end();it++)
        {
            if(it->second.size()==1)
            {
                return it->second[0];   //不行因为unoreder——map排序也不确定啊
            }
     
        }
        
        return -1;
        */
        
        
        for(auto it=str.begin();it!=str.end();it++)
        {
            
            if(result[*it].size()==1)
            {
                return result[*it][0];   //这样写居然也对，分离出vector
                //vector<int> res=result[*it];   //调用拷贝构造函数了
                //return res[0];
            }
                
        }
        return -1;
        
        
    }
};
