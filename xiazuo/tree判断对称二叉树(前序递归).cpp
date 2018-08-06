//注意另外设计一个递归函数，不要重用原来的函数，并且就是一个前序递归

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
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 1;
        return fenge(pRoot->left,pRoot->right);
    }
    
    bool fenge(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot1==NULL&&pRoot2==NULL)
            return 1;
        else if(pRoot1==NULL&&pRoot2!=NULL)
            return 0;
        else if(pRoot1!=NULL&&pRoot2==NULL)
            return 0;
        if(pRoot1->val!=pRoot2->val)     //这是先看自己再看孩子，就是前序递归
            return 0;
        return fenge(pRoot1->left,pRoot2->right)&&fenge(pRoot1->right,pRoot2->left);
    }
};
