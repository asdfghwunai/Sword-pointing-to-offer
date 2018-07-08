//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*--失败原因----
因为我想像归并排序那样先一直分割，分割到最后开始回溯处理，但是问题是左子树的最后结点在最右边，右子树的最后结点在最左边，找不到一种统一方法处理啊
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
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return NULL;
        digui(pRootOfTree);  //整理一下
        TreeNode *head=NULL;
        
    }
    
    TreeNode *digui(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return NULL;      //什么也不做
        
        //---还没对子树处理前先保存好左右子树的头----
        TreeNode *p_right=pRootOfTree->left;
        while(p_right->right)
        {
            p_right=p_right->right;
        }
        TreeNode *p_left=pRootOfTree;
        while(p_left->left)
        {
            p_right=p_right->right;
        }
        
        TreeNode* left=digui(pRootOfTree->left);
        TreeNode* right=digui(pRootOfTree->right);
        if(left)
        {
            left->right=root;
            root->left=left;
        }
        if(right)
        {
            root->right=right;
            right->left=root;
        }
        ruturn p;
        
    }
    
};
/*--方法---还是太傻了，看不到全局
首先得确定用中序遍历的方法，和一般中序不一样的是多个lastNode，然后连接起来
我刚发现递归调用返回就是前面都执行好了，没执行的递归函数就是还没执行好

*/

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        //if(pRootOfTree==NULL)
        //    return NULL;
        TreeNode* lastNode=NULL;
        digui(pRootOfTree,&lastNode);  //整理一下
        
        while(lastNode&&lastNode->left) //从尾巴到头遍历
        {
            lastNode=lastNode->left;
        }
        return lastNode;
    }
    
    void digui(TreeNode* pRootOfTree,TreeNode** last)
    {
        if(pRootOfTree==NULL)
        {
            *last=NULL;
            return;
        }
        if(pRootOfTree->left)   //这里有个小玄机，就是last不能回到NULL，否则和逻辑不符
           digui(pRootOfTree->left,last);  //假设左边弄好了
        pRootOfTree->left=*last;
        if(*last)      //倒数第二个实体开始连接
        {
            
            (*last)->right=pRootOfTree;
        }
            
        *last=pRootOfTree;
        if(pRootOfTree->right)
             digui(pRootOfTree->right,last);  //处理右边，这时右边还没好呢
    }
    
};
