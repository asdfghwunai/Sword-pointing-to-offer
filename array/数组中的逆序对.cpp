/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5
*/

/*
归并排序类型题，在归并排序中要统计一些信息，排序是从大到小排，前面的数组元素大于后面的比如 5 2 1和 7  4 3融合时，5>4,统计就要加2（5 4和 5 3）
还有一个问题是int换long long int，不然溢出
*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()<=1)
            return 0;
        int *array=new int[data.size()]; //没办法就只能用动态数组了
        int *temp=new int[data.size()];
        for(int i=0;i<data.size();i++)
        {
            array[i]=data[i];
        }
        int n=data.size();
        
        long long count=merge_sort(array,n,temp);
        return count%1000000007;
    }
    
    
    long long merge_sort(int *a,int n,int *c)
    {
        if(n==1)
            return 0;
        long long left=merge_sort(a,n/2,c);   //排左半边
	    long long right=merge_sort(a+n/2, n-n / 2, c);  //排右半边
	    long long count=merge(a,n/2,a+n/2,n-n/2,c);   //融合
        return left+right+count;
    }
    
/*
方法:
先自顶向下分割成越来越小的块，当到达最小的块时开始返回，然后自底向上融合
*/
long long merge(int a[],int m,int b[],int n,int c[])
{
    long long count=0;
	int k = 0;

	int i = 0,j=0;
	while (i < m&&j < n)  //方法   双指针
	{
		if (a[i] <= b[j])
		{
			//c[k++] = a[i++];
            c[k++] = b[j++];   //从大到小排
		}
		else
        {
            //c[k++] = b[j++];  //这里出现异类
            c[k++] = a[i++];
            count+=n-j;   //5 2 1 和7 4 3举例
        }
			
	}
	for (; i < m; )
		c[k++] = a[i++];
	for (; j < n; )
		c[k++] = b[j++];

	for (int i = 0; i < m + n; i++)    //转移值
		a[i] = c[i];
    return count%1000000007;

	/*
	for (int i = 0; i < m + n;i++)
	{
		cout <<a[i] <<" ";
	}
	*/
		
}
};
