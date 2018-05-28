/*
输入一个链表，输出该链表中倒数第k个结点。
*/

/*----方法-----
双指针，放一个先走到第k个结点，后面再开始走

*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	    
	if(pListHead==NULL||k==0)	//这个是offer说要考虑鲁棒性
	    return NULL;
	    
        ListNode *fast=pListHead;
        ListNode *slow=pListHead;
        
        for(int i=1;i<=k-1&&fast;i++)  //循环k-1次到第k个结点
            fast=fast->next;
        if(fast==NULL)    //就是fast直接指向NULL说明链表长度不够
            return NULL;
        
        //while(fast)    //fast达到末尾时,slow正好差n+1-k步
        while(fast->next)    //fast指向最后一个节点结束
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
