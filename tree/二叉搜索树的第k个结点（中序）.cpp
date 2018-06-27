/*
给定一颗二叉搜索树，请找出其中的第k小的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
class Solution {
public:
    void digui(TreeNode** target,TreeNode* pRoot, int &k)  //k是公有的
{
	
	if (pRoot == NULL)
		return;     //我感觉返回NULL后那target会咋办，不太对，其实这是栈，后面的target会覆盖

	digui(target,pRoot->left, k);
	if (k == 1)
		*target = pRoot;  //看现在
	if (pRoot != NULL)    //条件是废话其实
		k--;
	if (k >= 1)    //如果左子树递归完都知道答案了就没必要看右边了，提前结束
		digui(target,pRoot->right, k);    //其实这是有条件的钻
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == NULL || k == 0)
		return NULL;   //一般刚开始要判断异常条件的都要再写个递归函数处理
	TreeNode* target = NULL;
	digui(&target,pRoot, k);
	return target;     //其实这个target也是个栈内存，但是其指向内容是堆内存，所以就能返回
}
 
     
};
