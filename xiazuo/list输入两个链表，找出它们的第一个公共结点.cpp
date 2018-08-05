//不知道为啥通不过啊,感觉没错啊

//就是因为局部变量的问题,导致出错
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
        if(pHead1==NULL||pHead2==NULL)
            return NULL;
        int len1=0;
        int len2=0;
        
        ListNode *p1=pHead1,*p2=pHead2;
        while(p1!=NULL)
        {
            len1++;
            p1=p1->next;
        }
        
        while(p2!=NULL)
        {
            len2++;
            p2=p2->next;
        }
        int step=abs(len1-len2);
        if(len1>len2)
        {
            //ListNode *p1=pHead1;
             //ListNode *p2=pHead2;    //这句话少加了,这个我居然写成局部变量了
            p1=pHead1;
            p2=pHead2;
            while(step!=0)
            {
                p1=p1->next;
                step--;
            }
        }
        else
        {
            //ListNode *p1=pHead1;    //这句话少加了
            //istNode *p2=pHead2;
            p1=pHead1;
            p2=pHead2;
            while(step!=0)
            {
                p2=p2->next;
                step--;
            }
        }
        
        while(p1&&p2)
        {
            if(p1==p2)
                return p1;
            else
            {
                p1=p1->next;
                p2=p2->next;
            }
        }
        return NULL;
    }
};
