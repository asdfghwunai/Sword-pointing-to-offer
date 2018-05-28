/*
输入一个链表，反转链表后，输出链表的所有元素。

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
    ListNode* ReverseList(ListNode* pHead) {
        //方法 --有俩指针，prev是前结点，维持不变，cur是遍历结点，一点点向后推
        
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        
        ListNode *dummy=new ListNode(-1);
        
        dummy->next=pHead;
        ListNode *prev=pHead,*cur=prev->next;
            
        while(cur)
        {
            prev->next=cur->next;  //逻辑一看懂就很简单了
            cur->next=dummy->next;   //注意这里是dummy->next,不是prev->next;
            dummy->next=cur;
            
            cur=prev->next;
        }
        
        return dummy->next;
    }
};
