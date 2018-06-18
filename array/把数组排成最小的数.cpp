/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

/*
方法照人家，就是一个排序规则是俩数谁放前谁放后看谁大小，这样最后组成的数就小，我感觉后面新放的要和前面所有已放的一一进行比对决定放哪数
突然发现一个技巧，以后想比较大数的大小就直接把整数转成字符串，然后调用>或<号多好

to_string(int或其他类型)转化不熟，这个函数当成算法的一种，还有成员函数调用comp函数得用static
*/
class Solution {
public:
    static bool comp(const int& a,const int& b)
    {
        string A;
        string B;
        A=to_string(a)+to_string(b);
        B=to_string(b)+to_string(a);
        return A<B; 
    }
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size()==0)
            return "";
        sort(numbers.begin(),numbers.end(),comp);
        string result;
        for(int i=0;i<numbers.size();i++)
        {
            result+=to_string(numbers[i]);
        }
        return result;
    }
};
