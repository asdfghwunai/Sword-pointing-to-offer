/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

/*
偷懒做法直接搞起来，更通用一些，不再去研究边边角角的细节了
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            queue<TreeNode*> q,q_temp;
            vector<int>  temp;
            vector<vector<int> > result;
            if(pRoot==NULL)
                return result;
            
            q.push(pRoot);
            temp.push_back(pRoot->val);
            result.push_back(temp);
            temp.clear();
            while(!q.empty())
            {
                TreeNode* p=q.front();
                q.pop();
                if(p->left)   //压左
                {
                    q_temp.push(p->left);
                    temp.push_back(p->left->val);
                }
                if(p->right)
                {
                    q_temp.push(p->right);
                    temp.push_back(p->right->val);
                }
                if(q.empty())  //转移
                {
                    if(!q_temp.empty())
                    {
                         result.push_back(temp);
                         temp.clear();
                         q=q_temp;
                         //q_temp.clear();
                    
                         while (!q_temp.empty()) q_temp.pop();  //清空只能这样
                    }
                    else
                    {
                        break;
                    }
                }
                   
               
                    
            }
            
            for(int i=0;i<result.size();i++)
            {
                if(i%2==1)
                   reverse(result[i].begin(),result[i].end());
            }
            return result;
        }
    
};
