/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

class Solution {
public:
    string ReverseSentence(string str) {
        //思路先来个大反转，再一小段一小段反转
        reverse(str.begin(),str.end()); 
        
        int first=0;
        int last=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                last=i;
                reverse(str.begin()+first,str.begin()+last);
                first=i+1; //改变下一段的起点
            }
        }
        reverse(str.begin()+first,str.end()); //最后一次小反转
        
        return str;
    }
};
