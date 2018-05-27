/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

/*
结束标志是两个索引挨着，不是找到一个目标值
想两个索引挨着就必须=mid,而不是mid-1，比如 3 0 1，a[mid]<a[last]时所以last=mid=1而不是last=0
first和last要变到子递增或子递减序列的开头，不能跳跃
我假设数组确实旋转了，旋转度大于0
*/


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return 0;
        int first=0;
        int last=rotateArray.size()-1;
        while(1)
        {
            
            int mid=(first+last)/2;
            //if(rotateArray[mid]<rotateArray[mid+1]&&rotateArray[mid]<rotateArray[mid-1])   //找到的条件
            //    return rotateArray[mid];   //不是找目标值，而是找索引值
            
            if(last-first==1)
                break;
            if(rotateArray[mid]<=rotateArray[last])   //右边有序不可能了，到左边找
                last=mid; 
            else if(rotateArray[mid]>=rotateArray[first])  //这里有=推测是有的样例存在一样的元素，非递减
                first=mid;
        }
        return rotateArray[last];
    }
};
