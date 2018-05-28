/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
/*---方法---略微看了一下书的答案，直接动手写一遍成
【先根据前序遍历找到根节点一样的地方，找到后再检查根节点开始的子树一样不样(以树2为基准)】这一过程返回为真了就不用看proot1的左右子树了
用到了前序遍历,在检查过程中:一般情况下，根节点一样左右子树还要都对才行，像检查平衡二叉树
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result;
        if(pRoot2==NULL)  //空树
            return false;
        if(pRoot1==NULL)
            return false;  //proot1看完了
        if(pRoot1->val==pRoot2->val)
            result=jiancha(pRoot1,pRoot2);
        if(!result)   //自己不行就检查左边孩子群
           result=HasSubtree(pRoot1->left,pRoot2);
        if(!result)   //左边孩子群不行就检查右边孩子群
           result=HasSubtree(pRoot1->right,pRoot2);
        
        return result;  //前面行的话就行，不行的话就看右孩子群了
    }
    
    bool jiancha(TreeNode* pRoot1, TreeNode* pRoot2)  //照着proot2走
    {
        bool result_left,result_right;
        if(pRoot2==NULL)  //2已经完了
            return 1;
        if(pRoot1==NULL&&pRoot2!=NULL)  //1完2没完
            return 0;               //上面俩终止条件
	    
        if(pRoot1->val!=pRoot2->val)    //一般情况
            return 0;
        
        result_left=jiancha(pRoot1->left,pRoot2->left);
        result_right=jiancha(pRoot1->right,pRoot2->right);
        return result_left&&result_right;
        
    }
};
