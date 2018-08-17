递归解法：

（1）如果二叉树为空或者k<1返回0

（2）如果二叉树不为空并且k==1，返回1

（3）如果二叉树不为空且k>1，返回左子树中k-1层的节点个数与右子树k-1层节点个数之和

参考代码如下：

int GetNodeNumKthLevel(BinaryTreeNode* pRoot,int k)

{

    if(pRoot== NULL|| k <1)

        return0;

    if(k==1)

        return1;

    int numLeft=GetNodeNumKthLevel(pRoot->m_pLeft, k-1); //左子树中k-1层的节点个数

    int numRight=GetNodeNumKthLevel(pRoot->m_pRight, k-1); //右子树中k-1层的节点个数

    return (numLeft+ numRight);

}
