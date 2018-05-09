/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/


//方法---- 入队只是一个存储问题,没啥好说的。。 出队就是一个技巧
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            int len=stack1.size();
            for(int i=0;i<len-1;i++)     //stack1灌到stack2顺序就正常了。以后直接从stack2取就行
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int result=stack1.top();
            stack1.pop();
            return result;
        }
        else
        {
            int result=stack2.top();
            stack2.pop();
            return result;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
