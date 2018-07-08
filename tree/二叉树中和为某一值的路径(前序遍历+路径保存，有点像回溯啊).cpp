/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/*----方法---
前序遍历，到路径末尾看满不满足条件，满足就记录，返回上一级时要还原下一级加的值
考虑好哪些变量是全局的，全局的就用引用，不是全局的就用指针和实体
*/

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
        vector<int> res;
        int val=0;
        if(root==NULL)   //注意一些条件你得写，说明你考虑了
            return result;
        digui(root,expectNumber,result,val,res);  //得会设计函数啊，用实体还是引用
        return result;
    }
    
    
    void digui(TreeNode* root,int expectNumber,vector<vector<int> > &result,int &val,vector<int> &res)
    {
        if(root==NULL)   //一端为空直接不处理，这是防止前面出现出现那种单叶结点，这句话也可不加，后面digui弄到if里
            return;
        if(root->left==NULL && root->right==NULL)   //到头了
        {
            val+=root->val;        //我错在这个地方，少加了，根本到不了下面,晕了
            res.push_back(root->val);
            if(val==expectNumber)  //相等的话保存路径
            {
                result.push_back(res);
            }
            return;
        }
        
        val+=root->val;
        res.push_back(root->val);
        digui(root->left,expectNumber,result,val,res);
        if(root->left)    //从左子树返回，还原那些值
        {
            val-=root->left->val;
            res.pop_back();
        }
        digui(root->right,expectNumber,result,val,res);
        
        if(root->right)
        {
            val-=root->right->val;
            res.pop_back();
        }
        
        
    }
};
