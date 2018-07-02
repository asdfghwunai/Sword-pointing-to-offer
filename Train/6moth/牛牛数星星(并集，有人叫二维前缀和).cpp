/*
链接：https://www.nowcoder.com/questionTerminal/1bf5b56583f747e98741e37652e5a63e
来源：牛客网

一闪一闪亮晶晶，满天都是小星星，牛牛晚上闲来无聊，便躺在床上数星星。
牛牛把星星图看成一个平面，左上角为原点(坐标为(1, 1))。现在有n颗星星，他给每颗星星都标上坐标(xi，yi)，表示这颗星星在第x行，第y列。
现在，牛牛想问你m个问题，给你两个点的坐标(a1, b1)(a2，b2)，表示一个矩形的左上角的点坐标和右下角的点坐标，请问在这个矩形内有多少颗星星（边界上的点也算是矩形内）。
输入描述:

第一行输入一个数字n(1≤n≤100000)，表示星星的颗数。
接下来的n行，每行输入两个数xi和yi(1≤xi，yi≤1000），表示星星的位置。
然后输入一个数字m(1≤m≤100000), 表示牛牛询问问题的个数。
接下来m行，每行输入四个数字a1，b1，a2，b2(1≤a1＜a2≤1000), (1≤b1＜b2≤1000）
题目保证两颗星星不会存在于同一个位置。



输出描述:

输出一共包含m行，每行表示与之对应的每个问题的答案。

示例1
输入

4
1 1
2 2
3 3
1 3
4
1 1 2 2
1 1 3 3
2 2 3 3
1 2 2 3

输出

2
4
2
2
*/

/*
常规做法   50%，其实肯定有规律的
*/
#include<iostream>
 
using namespace std;
 
int main()
{
    /*
    int **a = NULL;  //我连二维数组建立都不会了
    int num = 0,left,right;
    cin >> num;
    a = new int*[num];
    for (int i = 0; i < num; i++)
        a[i] = new int[num];
 
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            a[i][j] = 0;
        }
    }
    */                               //内存溢出，原因是我把星星个数当位置的行和列了，50%通过率
    
    int num = 0,left,right;
    cin >> num;
    int a[1001][1001]; 
    memset(a,0,sizeof(a));   //不用建那么大的二维数组，我搞错了，70%通过率，时间复杂度太大
     
    for (int i = 0; i < num; i++)
    {
        cin >> left >> right;
        a[left - 1][right - 1] = 1;
    }
    int problem;
    cin >> problem;
    int zuo1, zuo2, zuo3, zuo4;
    int count=0;
    for (int i = 0; i < problem; i++)
    {
        cin >>zuo1 >> zuo2>>zuo3>>zuo4;
        count = 0;
        for (int i = zuo1 - 1; i <= zuo3 - 1; i++)
        {
            for (int j = zuo2 - 1; j <= zuo4 - 1; j++)
            {
                if (a[i][j] == 1)
                    count += 1;
            }
        }
        cout << count << endl;
         
    }
 
    return 0;
}

//--------------------------标准答案啊
#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1e3 + 5;   //这是个好习惯
int num[maxn][maxn];      
int mp[maxn][maxn];    //星星图，放全局估计是防止栈溢出

int n, m;    //星星和问题数量
int x,y;    //星星的位置
int a1, b1, a2, b2;  //问题的坐标
int main()
{
    memset(num, 0, sizeof(num));
    memset(mp, 0, sizeof(mp));
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        mp[x][y]++;
    }


     for(int i = 1; i < maxn; i++)   //计算该点左上角有多少星星，注意起点坐标为(1,1)
     {
        for(int j = 1; j < maxn; j++) {
            num[i][j] = num[i - 1][j] + num[i][j - 1] + mp[i][j] - num[i - 1][j - 1];
        }
    }


    scanf("%d", &m);
    for(int i = 0; i < m; i++)   //通过num图直接计算
    {
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        printf("%d\n", num[a2][b2] - num[a1 - 1][b2] - num[a2][b1 - 1] + num[a1 - 1][b1 - 1]);
    }
    
    return 0;
}
