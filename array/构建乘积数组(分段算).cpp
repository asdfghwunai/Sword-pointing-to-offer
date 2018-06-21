/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

/*
先画个图就好理解了
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(),1);
        if(A.size()==0)
          return B;
      
      for(int i=1;i<A.size();i++)   //第二行开始
      {
          B[i]=B[i-1]*A[i-1];   //先得到一半再说
      }
      
        int temp=1;
      for(int i=A.size()-2;i>=0;i--)   //倒数第二行开始
      {
          temp*=A[i+1];
          B[i]*=temp;     //补另一半
      }
        return B;
    }
};
