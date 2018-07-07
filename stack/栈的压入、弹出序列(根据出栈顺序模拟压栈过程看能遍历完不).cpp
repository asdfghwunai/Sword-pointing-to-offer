/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

/*----方法----
问题转换成在popV中一个个遍历，查找时两种大情况:（1）要么直接在栈顶中找到，（2）找不到就要接着压栈，直到找到，找不到就真的没有了。
以上两种情况只要找到就接着遍历下一个

我确实是看offer说用了辅助栈，然后睡觉时仔细想了想，把算法想明白了，直接一编一遍过，offer说是举例，我倒感觉是转化问题，你举例也看不出这俩数组怎么联系起来啊
我看了offer的算法思想和我想的一模一样，但程序我就不看了
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int size_ru=pushV.size();
        int size_chu=popV.size();
        stack<int> s;
        int i=0;
        for(int j=0;j<popV.size();j++)  //一个数一个数遍历
        {
            int flag=0;
            if(!s.empty()&&s.top()==popV[j])  //直接在栈里找到了
            {
                    s.pop();
                    flag=1;
            }
            else
            {
                while(pushV[i]!=popV[j]&&i<popV.size())
                {
                    s.push(pushV[i]);
                    i++;
                }
                if(i==popV.size())  //一直没找到
                    flag=0;
                else
                {
                    i++;    //找到时i对应的数正好就是，也不用压了再弹，直接跳过就行
                    flag=1;
                }
            }
            if(flag==0)
                return 0;
        }
        return 1;
    }
};
