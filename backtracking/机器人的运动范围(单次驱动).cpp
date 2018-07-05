/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
请问该机器人能够达到多少个格子？

*/

/*
还是有条件的前序遍历，它这个算起点(0,0)了
*/

#include<iostream>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		int count = 0;
		bool *visited = new bool[rows*cols];
		memset(visited,0,rows*cols*sizeof(bool));
		count=movingCountCore(threshold,rows,cols, 0, 0, visited);
		return count;
	}


	int movingCountCore(int threshold, int rows, int cols,int row, int col, bool *visited)
	{
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited) == 0)  //不行了直接返回
			return count;

		visited[row*cols+col] = 1;  //为啥1加呢？因为检查自己通过了规则，所以加1次
		count = 1+movingCountCore(threshold, rows, cols, row-1, col, visited) + movingCountCore(threshold, rows, cols, row+1, col, visited)+
			movingCountCore(threshold, rows, cols, row, col-1, visited) + movingCountCore(threshold, rows, cols, row, col+1, visited);
		return count;
	}
	bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
	{
		if (row >= 0 && row < rows && col >= 0 && col < cols && visited[cols*row + col] == 0 && getdigitNum(row) + getdigitNum(col) <= threshold)
			return 1;
		return 0;
	}

	int getdigitNum(int a)
	{
		int sum = 0;
		while (a)
		{
			sum += a % 10;
			a = a / 10;
		}
		return sum;
	}
};
