/*
一个链表中包含环，请找出该链表的环的入口结点。
*/


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

/*
照搬Leetcode的，不写了
注意起点一样，一个走s步，一个走2s步；然后这道题解法还涵盖了判断是否有环
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *head=pHead;
        ListNode *pre=head;
        ListNode *cur=head;
        if(head==NULL || head->next==NULL)
            return NULL;
        
       //如果结点个数是偶数个的话，slow指向中间两个元素的右边那个 比如1->2->NULL,slow是2，fast是null，和sort list不太一样
       //我知道为啥slow和cur一开始都是head了，因为要满足slow走s步，fast走2s步，但是这个返回的中点不是标准中点
       
        while(cur&&cur->next)    //这个解法还判断是否有环
        {
           cur=cur->next->next;
           pre=pre->next;
           if(cur==pre)      
           {
               ListNode *p=head;
               while(p!=cur)   //用到一个规律
               {
                   cur=cur->next;
                   p=p->next;
               }
               return p;
           }
            
        }
        return NULL;
    }
};
