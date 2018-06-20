/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

/*
构造函数解法，就是不知道为啥得清0，不清会多调用一次
*/

 class Temp{
        public:
        Temp()
        {
            N++;
            sum+=N;
        }
     
        static int Getsum()
        {
            return sum; 
        }
         
         static void reset(){N=0;sum=0;}
     
        private:
        static int N;
        static int sum;
    };
int Temp::N=0;
int Temp::sum=0;

class Solution {
public:
   
    int Sum_Solution(int n) {
        Temp::reset();     //不知道为啥会多加1次，必须清空
        Temp *a=new Temp[n];
        delete[] a;  //可以删除的，静态函数和对象没关系
        a=NULL;
        
        return Temp::Getsum();
    }
};
