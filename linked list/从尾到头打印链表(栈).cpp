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


/*
方法2---用递归
我确实是一下子写出来，不过写的过程中也是感觉着对才这样写
原则是先解决孩子，再解决自己
*/
class Solution {
public:
    void digui(ListNode* head,vector<int> &result)
    {
        if(head==NULL)
            return ;
        digui(head->next,result);  //先转移到孩子，再弄自己，当延迟操作
        result.push_back(head->val);
    }
    
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        
        digui(head,result);   //人家只要一个result，首先想到的是要用引用
        return result;
    }
};
