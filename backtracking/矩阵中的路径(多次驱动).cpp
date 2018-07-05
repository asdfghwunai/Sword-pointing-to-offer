/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

/*
感觉和前面一道题挺像的，就是有条件前序遍历，这里有好多递归起点，所以刚开始要用for循环，二叉树是只有一个递归起点就是根
*/

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows<1 || cols<1 || str == NULL)
			return 0;
		bool *visited = new bool[rows*cols];
		memset(visited, 0, rows*cols*sizeof(bool));

		int len = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (hasPathCore(matrix, rows, cols, str, visited, i, j, len))
					return 1;   //早早结束了
			}
		}
		return 0;
	}

	bool hasPathCore(char* matrix, int rows, int cols, char* str,bool *visited,int row,int col,int &len)
	{
		if (str[len] == '\0')
			return 1;
		if (row >= 0 && row < rows && col >= 0 && col < cols &&visited[row*cols + col] == 0 &&  matrix[row*cols + col]==str[len]) 
		{                                                    //visited[row*cols + col]写成visited[row*rows + col]
			len++;
			visited[row*cols + col] = 1;    //写错
			if (hasPathCore(matrix, rows, cols, str, visited, row + 1, col, len) || hasPathCore(matrix, rows, cols, str, visited, row - 1, col, len)
				|| hasPathCore(matrix, rows, cols, str, visited, row, col + 1, len) || hasPathCore(matrix, rows, cols, str, visited, row, col - 1, len))
				return 1;
			len--;     //前面没做到后面就恢复
			visited[row*rows + col] = 0;   //写错

		}
		return 0;   //大殿后
	}

};
