/*
输入两个链表，找出它们的第一个公共结点。
*/

/*
先遍历一遍得到长度，谁长谁先走几步，然后都从头走，一样就跳出

我现在好像啥都先想到暴力法，咋这么笨呢？压根不屑于找规律了
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1=get_lenth(pHead1);
        int len2=get_lenth(pHead2);
        if(len1==0||len2==0)
            return NULL;
        int bu=abs(len1-len2);
        if(len1>len2)   //谁大谁先走几步
        {
            while(bu>0)
            {
                pHead1=pHead1->next;
                bu--;
            }
            
        }
        else if(len1<len2)
        {
              while(bu>0)
            {
                pHead2=pHead2->next;
                bu--;
            }
        }
        
        while(pHead1&&pHead2)
        {
            if(pHead1==pHead2)
                return pHead1;
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        return NULL; //编译器可不知这句是废话不
    }
    
    int get_lenth(ListNode* head)
    {
        if(head==NULL)
            return 0;
        ListNode*p=head;
        int len=0;
        while(p)
        {
            len+=1;
            p=p->next;
        }
        return len;
    }
};
