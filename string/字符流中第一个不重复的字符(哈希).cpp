/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
*/

class Solution
{
public:
  //Insert one char from stringstream
    unordered_map<char,int> result;
    vector<char> vec;
    void Insert(char ch)
    {
         result[ch]++;  //好像可以直接加
        vec.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if(vec.size()==0)
            return '#';
        for(int i=0;i<vec.size();i++)
        {
            if(result[vec[i]]==1)
                return vec[i];
        }
        return '#';
    }

};
