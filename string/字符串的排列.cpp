/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba
*/
/*---方法----
先依次交换首字母，然后递归得到子串的结果，然后合并，返回上一层
*/

class Solution {
public:
    void swap(char &a,char &b)
    {
        char temp=a;
        a=b;
        b=temp;
    }
    
    vector<string> digui(string str)
    {
        vector<string> result;
        if(str.size()==1)    //终止条件
        {
            result.push_back(str);
            return result;
        }
        else     //向下层递归
        {
            for(int i=0;i<str.size();i++)
            {
                   
                
                    swap(str[0],str[i]);   //交换
                    char c=str[0];
                    //vector<string> last_result=Permutation(str.substr(str.begin()+1,str.end())); //得到上次结果
                    vector<string> last_result=digui(str.substr(1,str.size()-1));
                    for(int j=0;j<last_result.size();j++)  //插入首字母到上次结果
                    {
                        last_result[j].insert(last_result[j].begin(),c);
                        result.push_back(last_result[j]);
                    }
                
                    swap(str[0],str[i]);//还原
                
                
            }
            return result;   //非必须，要返回值就返回呗
            
        }
    }
    
    
    vector<string> Permutation(string str) {
        vector<string> result=digui(str);  //下面去重
        set<string> result_set;
        for(int i=0;i<result.size();i++)
        {
            result_set.insert(result[i]);
        }
        result.clear();
        for(auto iter=result_set.begin();iter!=result_set.end();iter++)
        {
            result.push_back(*iter);
        }
        return result;
    }
};
