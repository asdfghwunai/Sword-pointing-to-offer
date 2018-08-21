给定一个含有n个元素的整型数组a，其中只有一个出现奇数次，找出这个元素。

int FindElementWithOddCount(int*a, int n)
{
        int r = a[0] ;

        for (int i =1; i < n; ++i)
        {
                r ^= a[i] ;
        }

        return r ;
} 
