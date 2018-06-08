/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

/*---方法---
我分析出用递归先判断左子树，再判断右子树，但是我卡在了怎么知道哪些结点是左子树，哪些是右子树

这道题就是先把最右边的当分割点，然后遍历剩余结点，找出左子树和右子树序列，（我当时有点感觉一个序列只能对应一个二叉树的表示，你分割的不一样
二叉树可能表示不出来其实感觉错了，这种感觉来自那个根据给出的前序构造二叉树（里面有NULL，所以一个序列只能有一个表示））

接着说，右子树有不正常的点就本次直接结束，否则分割出左右子树，进下次递归判断

这种判断真假的题大原则就是直接奔着正常的情况去（就是只考虑一条路），中间有任何异常就返回非
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0)   //人家规定刚开始是[]就是0，与下面的矛盾，只能分开写
            return 0;
        return digui(sequence);
        
        
    }
    
    bool digui(vector<int> sequence)
    {
        if(sequence.size()==1)   //就是最后只剩一个结点
            return 1;
        
        if(sequence.size()==0)   //就是一边子树直接没了
            return 1;
        
        int root=sequence[sequence.size()-1];
        int dayu_start=0;
        for(dayu_start=0;dayu_start<sequence.size()-1;)
        {
            if(sequence[dayu_start]<root)   //找到第一个大于root的数
                dayu_start++;
            else
                break;
        }
        
        for(;dayu_start<sequence.size()-1;dayu_start++)  //检查右子树里的结点有异常没
        {
            if(sequence[dayu_start]<root)
            {
                return 0;
            }
        }
        vector<int> sequence_left;
        sequence_left.assign(sequence.begin(),sequence.begin()+dayu_start);
        vector<int> sequence_right;
        sequence_right.assign(sequence.begin()+dayu_start,sequence.begin()+sequence.size()-1);
        return digui(sequence_left)&&digui(sequence_right);
    }
};
