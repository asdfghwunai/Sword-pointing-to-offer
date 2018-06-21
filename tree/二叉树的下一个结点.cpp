/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

/*
有右子树就返回右子树最左边的节点，无右子树时，如果是父节点的左孩子，直接返回即可，如果是父节点的右孩子，向前回溯父节点，找到一个拐弯的（就是本节点是父节点的左孩子，然后输出父节点）
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        if(pNode->next==NULL)  //给定节点为根节点
        {
            //return pNode->right;   //就返回右节点是错的
            if(pNode->right==NULL)
                return NULL;
            else
            {
                TreeLinkNode *p=pNode->right;
                while(p->left)   //以右子树开始找到最左节点
                    p=p->left;
                return p;
            }
                
        }
        //下面是普通节点情况
        if(pNode->right!=NULL)
        {
            TreeLinkNode *p=pNode->right;
            while(p->left)   //以右子树开始找到最左节点
                 p=p->left;
            return p;
        }
        else   //没有右子树
        {
            if(pNode==pNode->next->left)    //给定节点为父节点的左节点，直接返回父节点
                return pNode->next;
            else if(pNode==pNode->next->right)
            {
                TreeLinkNode *p=pNode->next;   //以第一个父节点开始回溯
                while(p)
                {
                    if(p->next==NULL)
                        return NULL;   //到根节点没找到
                    if(p==p->next->left)
                        return p->next;
                    p=p->next;
                }
            }
            return NULL;   //这句话就是来个大殿后
        }
    }
};
