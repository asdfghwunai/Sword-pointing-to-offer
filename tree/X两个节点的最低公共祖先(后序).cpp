//二叉搜索树两个节点的最低公共祖先，参数为两个节点的值
BinaryTreeNode*lowestCommonAncestorOfBST(BinaryTreeNode*pNode, int nNodeOne, int nNodeTwo){
	if (pNode==NULL)
	{
	   return NULL;
	}
	if (pNode->m_nValue>nNodeOne && pNode->m_nValue>nNodeTwo)//当前节点的值大于这两个节点的值
	{
	return lowestCommonAncestorOfBST(pNode->m_pLeft, nNodeOne, nNodeTwo);//访问左子树
	}
	if (pNode->m_nValue<nNodeOne && pNode->m_nValue<nNodeTwo)//当前节点的值小于这两个节点的值
	{
	return lowestCommonAncestorOfBST(pNode->m_pRight, nNodeOne, nNodeTwo);//访问右子树
	}
	return pNode;//就是公共祖先
}
//二叉搜索树两个节点的最低公共祖先，参数为两个节点
BinaryTreeNode*lowestCommonAncestorOfBST(BinaryTreeNode*pNode, BinaryTreeNode*pNode1, BinaryTreeNode*pNode2){
	
	if (pNode==NULL)
	{
	return NULL;
	}
	if (pNode->m_nValue>pNode1->m_nValue && pNode->m_nValue>pNode2->m_nValue)//当前节点的值大于这两个节点的值
	{
	return lowestCommonAncestor(pNode->m_pLeft, pNode1, pNode2);//访问左子树
	}
	if (pNode->m_nValue<pNode1->m_nValue && pNode->m_nValue<pNode2->m_nValue)//当前节点的值小于这两个节点的值
	{
	return lowestCommonAncestor(pNode->m_pRight, pNode1, pNode2);//访问右子树
	}
	return pNode;//就是公共祖先
	
}

//============================================================

//两个节点的最低公共祖先，参数为两个节点
BinaryTreeNode* lowestCommonAncestor(BinaryTreeNode*pNode, BinaryTreeNode*pNode1, BinaryTreeNode*pNode2){
	//发现目标节点则通过返回值标记该子树发现了某个目标结点
	if (pNode == NULL || pNode == pNode1 || pNode == pNode2) return pNode;
	//查看左子树中是否有目标结点，没有为null
	BinaryTreeNode*left = lowestCommonAncestor(pNode->m_pLeft, pNode1, pNode2);
	//查看右子树是否有目标节点，没有为null
	BinaryTreeNode*right = lowestCommonAncestor(pNode->m_pRight, pNode1, pNode2);
	//都不为空，说明做右子树都有目标结点，则公共祖先就是本身
	if (left != NULL&&right != NULL) return pNode;
	//如果发现了目标节点，则继续向上标记为该目标节点
	return left == NULL ? right : left;
}
//两个节点的最低公共祖先，参数为两个节点的值
BinaryTreeNode* lowestCommonAncestor(BinaryTreeNode*pNode, int nNodeOne, int nNodeTwo){
	//发现目标节点则通过返回值标记该子树发现了某个目标结点
	if (pNode == NULL || pNode->m_nValue == nNodeOne || pNode->m_nValue == nNodeTwo) return pNode;
	//查看左子树中是否有目标结点，没有为null
	BinaryTreeNode*left = lowestCommonAncestor(pNode->m_pLeft, nNodeOne, nNodeTwo);
	//查看右子树是否有目标节点，没有为null
	BinaryTreeNode*right = lowestCommonAncestor(pNode->m_pRight, nNodeOne, nNodeTwo);
	//都不为空，说明做右子树都有目标结点，则公共祖先就是本身
	if (left != NULL&&right != NULL) return pNode;
	//如果发现了目标节点，则继续向上标记为该目标节点
	return left == NULL ? right : left;
}
