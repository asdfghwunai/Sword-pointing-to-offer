/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
三指针法，不一样就正常向后跑，一样就开始删
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
          ListNode *head=new ListNode(-1);
          head->next=pHead;
          if(pHead==NULL||pHead->next==NULL)
              return pHead;
          ListNode *pre=head,*cur=head->next,*hou=head->next->next;
        while(hou)
        {
            if(cur->val!=hou->val)
            {
                pre=pre->next;
                cur=cur->next;
                hou=hou->next;
            }
            else
            {
                while(hou&&hou->val==cur->val)  //找到不一样的
                    hou=hou->next;
                if(hou==NULL)   //直接结束,是为了解决重复4 4结尾的
                {
                    pre->next=NULL;
                    break;
                }
                else    //这个地方想想就明白了
                {
                    pre->next=hou;   //怎么从前向后接啊？
                    cur=hou;
                    hou=cur->next;
                }
                    
            }
        }
        return head->next;
          
    }
};
