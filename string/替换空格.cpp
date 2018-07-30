/*
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

/*方法
我是瞎做的，直接复制了一份，然后开始遍历，就像那个merge_sort的merge阶段

*/



class Solution {
public:
	void replaceSpace(char *str,int length) {
       char *str1=(char *)malloc(length+1);
        strcpy(str1,str);
        
        int i=0;
        int j=0;
        while(str[j]!='\0')
        {
            str[i]=str1[j];
            if(str1[j]==' ')
            {
               str[i]='%';
                str[i+1]='2';
                str[i+2]='0';
                i=i+3;
                j=j+1;
                continue;
            }
            i++;
            j++;
        }
        str[i]='\0';
	}
};
