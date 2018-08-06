/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:

输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。


*/

/*
先找到一个生成排列的规律
就是str[0]连到 str.substr(1)的所有排列前面就行

还有一个问题是有条件连接,就是长度差1再连接,不然前面的每次大循环长度都连好了,你这次循环又连,会超长的
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        vector<string> temp;
        unordered_set<string> s;
        if(str.size()==0)
            return result;
        

        digui(str,result);    //不要写错了
        for(int i=0;i<result.size();i++)
        {
            if(s.find(result[i])==s.end())
            {
                s.insert(result[i]);
                temp.push_back(result[i]);
            }
        }
        
        sort(temp.begin(),temp.end());     //还得排下序
        return temp;
    }
    
    void digui(string str,vector<string> &result)
    {
        if(str.size()==1)
        {
            result.push_back(str);
            return;
        }
        //犯了大忌,递归里有多个递归
        for(int i=0;i<str.size();i++)
        {
            swap(str[0],str[i]);      //交换
            digui(str.substr(1),result);    //不要写错了
            for(int i=0;i<result.size();i++)
            {
                if(result[i].size()==(str.substr(1)).size())    //有条件连接,长度满足的不用管了
                    result[i]=str[0]+result[i];   //进行连接
            }
                
           
            swap(str[0],str[i]);      //换回来
        }
       
        
    }
};
