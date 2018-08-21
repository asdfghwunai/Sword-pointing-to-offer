/*
给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，其他均只出现一次，每个数组元素只能访问一次。请找出这个数。

*/



方法1
直接进行总和-(1加1000)，会溢出

方法2
构造多重异或，即先构造一个1--1000的异或值, 然后进行相应的对这些数异或，因为重复数为3，所以最后剩的数就是了



void FindRepeat(int array[], int length)
{
    int result = 0;
    for(int i=1;i<=1000;i++)
        result ^= i;
    for(int i=0;i<=1000;i++)
        result ^= array[i];
    cout << result << endl;
}

