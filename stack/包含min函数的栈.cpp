/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

/*----方法----
能力还是不行啊，这种题说实话高手一下子不用想就能做出来

我好早之前确实不会做，看答案也迷迷糊糊，现在看offer说用辅助栈一下子写出来，确实不难，但是还是能力不够小题都能难死
*/

class Solution {
public:
    stack<int> s;
    stack<int> s1;
    int min_value;
    void push(int value) {
        if(s.empty())  //第一次进时理所当然是最小
            min_value=value;
        if(min_value>value)  //然后min记录到进这个数时最小的数
            min_value=value;
        s.push(value);
        s1.push(min_value);
    }
    void pop() {
        s.pop();
        s1.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return s1.top();
    }
};
