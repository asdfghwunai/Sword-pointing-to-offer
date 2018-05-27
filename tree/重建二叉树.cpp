/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*----方法-----
 要想重建二叉树，就是孩子建好了，自己也建好了，
 根据前序找根，遍历中序来分割中序（生成中序左孩子群，中序右孩子群），再回来分割前序（前序做孩子群，前序右孩子群）
 
 */
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0)     //这是一边正好为0
            return NULL;  
        /*
        if(pre.size()==1)   //这是一边正好为1,其实不用判断的
        {
            TreeNode *root=new TreeNode(pre[0]);   
            return root;
        }
        */
        
        int value=pre[0];
        auto it=find(vin.begin(),vin.end(),value);    //找不到是end(),不过不会找不到的
        TreeNode *root=new TreeNode(value);    //先弄自己
        
        vector<int> vin_left_haizi,vin_right_haizi;   //分割中序
        vin_left_haizi.assign(vin.begin(),it);  //左闭右开
        vin_right_haizi.assign(it+1,vin.end());
        
        vector<int> pre_left_haizi,pre_right_haizi;   //分割前序
        int left_size=vin_left_haizi.size();
        int right_size=vin_right_haizi.size();
        pre_left_haizi.assign(pre.begin()+1,pre.begin()+left_size+1);
        pre_right_haizi.assign(pre.begin()+left_size+1,pre.end());
        
        root->left=reConstructBinaryTree(pre_left_haizi,vin_left_haizi);
        root->right=reConstructBinaryTree(pre_right_haizi,vin_right_haizi);
        return root;
    }
};
