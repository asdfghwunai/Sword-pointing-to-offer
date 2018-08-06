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
        if(pHead==NULL|| pHead->next==NULL)
            return pHead;
        ListNode *prev=NULL;
        ListNode *cur=pHead;
        ListNode *temp=NULL;
        while(cur)      //cur到NULL。prev正好是末尾
        {
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
};
