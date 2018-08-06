//相当于把第一个解决好了，然后去解决孩子就行

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL&&pHead2==NULL)
            return NULL;
        else if(pHead1==NULL&&pHead2!=NULL)
            return pHead2;
        else if(pHead1!=NULL&&pHead2==NULL)
            return pHead1;                   //突然发现递归的返回只是返回给上一层，让上一层用，不是直接返回结果
        ListNode *head=NULL;
        if(pHead1->val<pHead2->val)
        {
            head=pHead1;
            head->next=Merge(pHead1->next,pHead2);
        }
        else
        {
            head=pHead2;
            head->next=Merge(pHead1,pHead2->next);
        }
        return head;
    }
};
