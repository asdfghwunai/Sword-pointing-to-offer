/*
其实算模拟法，模拟这个过程就行
*/

/*

现在你需要用一台奇怪的打字机书写一封书信。信的每行只能容纳宽度为100的字符，也就是说如果写下某个字符会导致行宽超过100，那么就要另起一行书写
信的内容由a-z的26个小写字母构成，而每个字母的宽度均会事先约定。例如字符宽度约定为[1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5]，那么就代表'a'到'd'四个字母的宽度分别是1,2,3,4，而'e'到'z'的宽度均为5
那么按照上述规则将给定内容S书写成一封信后，这封信共有几行？最后一行宽度是多少？

输入描述:

输入为两行：
第一行是存储了每个字符宽度的字符串，包含26个数字，以1个空格分隔，每个数字均小于等于10
第二行是存储了待输入字符的字符串S，字符串S的长度在1到1000之间



输出描述:

输出为信的行数以及最后一行所包含的字符个数，中间以1个空格分隔


输入例子1:

5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
helloworld


输出例子1:

1 50


例子说明1:

"5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5"规定每个字符宽度为5
"helloworld"是输入的字符串S
由于S共包含10个字符，也即共占用50个字符宽度，因此可以写在同一行


输入例子2:

5 5 5 5 5 5 10 10 10 10 10 10 10 10 10 10 10 10 5 5 5 5 5 5 5 5
hahahahahahahaha


输出例子2:

2 20


例子说明2:

"5 5 5 5 5 5 10 10 10 10 10 10 10 10 10 10 10 10 5 5 5 5 5 5 5 5"规定了每个字符宽度
"hahahahahahahaha"是输入的字符串S
由于h宽度为10，a宽度为5，因此'hahahahahahah'占用100字符宽度可以写在第一行，‘aha’写在第二行也即最后一行。因此字符宽度为20


*/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
 
int main()
{
    int x;
    
    unordered_map<char,int> suoyin;

    string str;
    for(int i=0;i<26;i++)
    {
        cin>>x;
        suoyin['a'+i]=x;
    }
    cin>>str;
    
    /*
    long long count=0;
    for(int i=0;i<str.size();i++)
        count+=suoyin[str[i]];
    long long res1=count/100;
    long long res2;
    if(count%100!=0)
    {
        res1+=1;
        res2=count%100;
    }
    else
    {
        res2=100;
    }

    cout<<res1<<" "<<res2;
    */    //错在算总体上了

    int res1=1,res2=0;
    for(int i=0;i<str.size();i++)
    {
        res2+=suoyin[str[i]];    //算一行
        if(res2>100)
        {
            res1++;
            res2=suoyin[str[i]];   //另起一行
        }
            
    }

    cout<<res1<<" "<<res2;
    
     
    return 0;
}
