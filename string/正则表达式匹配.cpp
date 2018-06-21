/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

/*
终止条件也有很大玄机
*/
class Solution {
public:
    bool match(char* str, char* pattern)   //return真是个好东西，把
    {
        /*
        if(*str=='\0')                //'\0'只能和'\0'匹配
            return *pattern=='\0';
        if(*pattern=='\0')
            return *str=='\0';     //处理不了"",".*"，答案是1，我是0
        */
        
        if(*str=='\0'&&*pattern=='\0')   //这俩终止条件也有玄机
            return 1;
        if(*str!='\0'&&*pattern=='\0')
            return 0;
        if(*(pattern+1)=='*')
        {
            
            if(*str!='\0'&&*pattern=='.'||*pattern==*str)   //*当0用
            {
                return match(str,pattern+2)||match(str+1,pattern+2)||match(str+1,pattern); //3条路,当0，当1，当无限
                //1235
                //12*4  2和4 3和4 3和2，像那leetcode版递归里出现循环不好
            }
            else   
            {
                return match(str,pattern+2);   //*当0次用，即清除   //像这个"",".*"就走这条路了，最后返回1
            }
        }
        else
        {
            if(*str!='\0'&&*pattern=='.'||*pattern==*str)
                return match(str+1,pattern+1);
            else
                return 0;
        }
    }
};
