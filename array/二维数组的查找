/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //方法   从最后一行开始向右遍历，找到大于target的第一个数跳出，这个数所在列的右边(包括此列)就是你要找的范围
        
        int rows=array.size();
        int cols=array[0].size();
        
        int i;
        for(i=0;i<cols;i++)
        {
            if(array[rows-1][i]==target)   //用最后一行来比对
                return 1;
            else if(array[rows-1][i]>target)
                break;
        }
        if(i==cols)
            return 0;
        else  
        {
            for(;i<cols;i++)
            {
                for(int j=0;j<rows;j++)
                {
                    if(array[j][i]==target)
                        return 1;
                }
            }
            return 0;
        }
    }
};
