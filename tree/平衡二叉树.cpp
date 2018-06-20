/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/*
就是看孩子深度差大不大于1，用到求二叉树深度
*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) //
            return 1;
        /*
        if(pRoot->left)    //条件1
        {
            if(pRoot->left->val>pRoot->val)
                return 0;
        }
         if(pRoot->right)
        {
            if(pRoot->right->val<pRoot->val)
                return 0;
        }
        */
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        if(abs(left-right)>1)  //条件只是深度相差一点就行，不用是二叉搜索树
            return 0;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
        
    }
    
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        
        return (left>right)?(left+1):(right+1);
    }
    
    
};
