/*
操作给定的二叉树，将其变换为源二叉树的镜像。
*/

/*---方法----
听他的，画画图，用到前序遍历，把遍历的访问改为交换左右孩子
*/

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL)
            return;    //终止条件，这也说明俩孩子都为空
        
        TreeNode *temp=NULL;
        temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        
    }
};
