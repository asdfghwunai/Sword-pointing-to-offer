/*
请实现两个函数，分别用来序列化和反序列化二叉树
*/

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

class Solution {
public:
    char result[10000];
    //int index=0;
    char* Serialize(TreeNode *root) {   
        int index=0;
        digui(root,result,index);
        return result;   //为啥用全局变量呢?因为不能返回局部变量,你想返回得在堆上给result分配内存
    }
    TreeNode* Deserialize(char *str) {
        TreeNode *root=NULL;
        if(str==NULL||strlen(str)==0)
            return NULL;
         
        int index=0;
        root=digui2(root,str,index);   //想更改只能返回一级指针,或你自己传入二级指针
        return root;
    }
     
    void digui(TreeNode *root,char *result,int &index)  //这个从根节点开始遍历可以确定遍历完,中间可以返回,就像普通的遍历一样
    {
       if(root==NULL)
       {
           result[index]='#';
           index++;
           result[index]='\0';   //先打个结束符
           return;
       }
       result[index]='0'+root->val;
       index++;
       result[index]='\0';
       digui(root->left,result,index);
       digui(root->right,result,index);
    }
     
    TreeNode* digui2(TreeNode *root,char *result,int &index)   //挺有意思的,不用考虑怎么结束,它会自动结束
    {
        if(result[index]=='#')
        {
            root=NULL;
            index++;   //就是空你也得给人家加个index,好下次读取下一个index
            return root;
        }
        
        int x=result[index]-'0';
        if(x<0)
            x=(x+128+128);   //推出来的,不是算出来的
        root=new TreeNode(x);
        index++;
        root->left=digui2(root->left,result,index);
        root->right=digui2(root->right,result,index);
        return root;
    }
};
