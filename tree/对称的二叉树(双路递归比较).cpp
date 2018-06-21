/*
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

/*
我只想说关前序什么事
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
       return digui(pRoot,pRoot);
    }
    
    bool digui(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot1==NULL&&pRoot2==NULL)
            return 1;
        if(pRoot1==NULL||pRoot2==NULL)
            return 0;
        if(pRoot1->val!=pRoot2->val)
            return 0;    //本层一样的话还得检查孩子
        //return digui(pRoot1->left,pRoot2->right)&&digui(pRoot1->right,pRoot2->left);
        return digui(pRoot2->right,pRoot1->left)&&digui(pRoot1->right,pRoot2->left);  //一样的，只要保证平级就行
    }

};
