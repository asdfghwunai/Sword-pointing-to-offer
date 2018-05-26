//输入一个链表，从尾到头打印链表每个节点的值。
/*
方法
我迟疑了一下，要不要那么简单，看书也是栈做的
*/


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> s;
        if(head==NULL)
        {
            return result;
        }
        ListNode *p=head;
        while(p!=NULL)
        {
            s.push(p->val);
            p=p->next;
        }
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};
