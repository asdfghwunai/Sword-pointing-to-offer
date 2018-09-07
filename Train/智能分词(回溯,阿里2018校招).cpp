/*


智能分词

分词是指将一个字符串分割成词语序列，其中所有词语都来自事先指定的词汇表。例如：
有字符串"github"，以及词汇表["git", "hub"]，那么分词方式为:"git hub"。

分词可能有多重方式，例如字符串"asdfjkl"，以及词汇表["as", "asd", "df", "fjkl", "jkl"]，可能有两种分词方法:"as df jkl"、"asd fjkl"。先定义每种分词方法的合理性得分为：分词方案中每个单词长度的平方和。例如上述两种分词方案的得分分别为 2^2 + 2^2 + 3^2 = 17，以及 3^2 + 4^2 = 25。

现给出词汇表（均为小写字母，单词最长50字符，最多10个万单词），以及一句话（均为小写字母，最长10万字符），找出最合理的分词方案。若有多种得分相同的最合理方案，输出长词尽量靠前的方案。例如"ab cdef"与"abcd ef"这两种最优方案得分相同，输出"abcd ef"。





输入:
第一行为待分语句；第二行为词汇表中的单词数量N；接下来N行，每行一个单词。
输出:
一行，分隔后的语句，以空格分隔各个单词。
输入范例:
asdfjkl
5
as
asd
df
fjkl
jkl
输出范例:
asd fjkl
*/

#include <iostream>
#include <hash_set>
#include <vector>
#include <string>
using namespace std;
int max = 0;
hash_set<string>   hs;
string ss;

vector<string> vec;
void digui(string str,int start,int len,vector<string> &vec)
{
	if (len == 0 || str.size()==0)
		return;
	if (ss.size() < len)    //取刚好满足长度的
		len = ss.size();
	string sub1, sub2;
	if (len == str.size())
	{
		sub1 = str.substr(start, len);
		sub2 = "";
	}
	else
	{
		sub1 = str.substr(start, len);
		sub2 = str.substr(len);
	}
	
	if (hs.find(sub1) != hs.end())
	{
		vec.push_back(sub1);
		digui(sub2, 0, max, vec);   //有的话就看下一小截
	}
	else
	{
		if (!vec.empty())
			vec.pop_back();
		digui(str, 0, len-1, vec);   //不满足就回退
	}

}
int main()
{
	cin >> ss;
	int n;
	cin >> n;
	string str;
	
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (max < str.size())
			max = str.size();
		hs.insert(str);
	}

	
	digui(ss, 0, max, vec);



	//while (1);
	return 0;
}



