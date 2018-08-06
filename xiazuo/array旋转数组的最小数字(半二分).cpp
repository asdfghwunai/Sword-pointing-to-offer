/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

/*
就是只分析题上的那个例子，这就是只分析最简单的情况，然后这个最简单恰好符合所有
*/


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int start=0;
        int end=rotateArray.size()-1;
        
        //这时无目标查找
        while(end-start>=1)
        {
            if(end-start==1)
                return min(rotateArray[start],rotateArray[end]);
            
            int mid=(start+end)/2;
            if(rotateArray[mid]>=rotateArray[start])
            {
                start=mid;
            }
            else
            {
                end=mid;
            }
        }
        //return rotateArray[start];
        return 0;
    }
};
