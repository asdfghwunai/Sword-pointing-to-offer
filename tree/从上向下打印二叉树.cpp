/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/*-----方法-----
标准的广度优先遍历写法，就照那个模式写即可，压栈时就要顺带访问
*/


class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;    //存储
        vector<int> result;
        if(root==NULL)
            return result;
        result.push_back(root->val);
        q.push(root);
        while(!q.empty())
        {
            TreeNode* gen=q.front();
            q.pop();
            if(gen->left)   //压左边
            {
                result.push_back(gen->left->val);
                q.push(gen->left);
            }
            if(gen->right)    //压右边
            {
                result.push_back(gen->right->val);
                q.push(gen->right);
            }
        }
        return result;
        
    }
};
