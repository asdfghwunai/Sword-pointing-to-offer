/*
又是晴朗的一天，牛牛的小伙伴们都跑来找牛牛去公园玩。但是牛牛想呆在家里看E3展，不想出去逛公园，可是牛牛又不想鸽掉他的小伙伴们，于是找来了公园的地图，发现公园是由一个边长为n的正方形构成的，公园一共有m个入口，但出口只有一个。公园内有一些湖和建筑，牛牛和他的小伙伴们肯定不能从他们中间穿过，所以只能绕行。牛牛想知道他需要走的最短距离并输出这个最短距离。
输入描述:

第一行输入一个数字n(1≤n≤1000)表示公园的边长
接下来会给你一个n*n的公园地图，其中 . 表示公园里的道路，@表示公园的入口，*表示公园的出口，#表示公园内的湖和建筑。牛牛和他的小伙伴们每次只能上下左右移动一格位置。
输入保证公园入口个数m(1≤m≤10000)且所有的入口都能和出口相连。



输出描述:

输出牛牛需要行走的最短距离。


输入例子1:

10
.@....##@.
......#...
...@..#...
###.......
....##..#.
...####...
@...##....
#####.....
..##*####.
#.........


输出例子1:

16
*/


#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
const int maxn = 1e3 + 5;

struct node {
    int x, y;
};
int dis[maxn][maxn];
char mp[maxn][maxn];
int n;
node a;    //记录开始结点坐标
node ed;     //记录结尾坐标
 
const int dx[] = {0, 1, 0, -1};         //其实这是走了一步
const int dy[] = {-1, 0, 1, 0};

int main()
{
    memset(mp, 0, sizeof(mp));
    memset(dis, -1, sizeof(dis));
    
    scanf("%d", &n);    //输入行列数
    for(int i = 0; i < n; i++) {
        scanf("%s", mp[i]);    //输入地图
    }
    
    queue<node> q;
    for(int i = 0; i < n; i++)                //转成一般的数据
    {           
        for(int j = 0; j < n; j++) {
            if(mp[i][j] == '@') {
                a.x = i;
                a.y = j;
                q.push(a);
                dis[i][j] = 0;    //刚看明白，到自己的距离是0
            }
            if(mp[i][j] == '*') {
                ed.x = i;
                ed.y = j;
            }
        }
    }


    while(q.size()) 
    {
        node p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)         //测试4个新位置
        {
            int px = p.x + dx[i];    
            int py = p.y + dy[i];
            if(dis[px][py] == -1 && px >= 0 && px < n && py >= 0 && py < n && mp[px][py] != '#') 
            {
                node pp;
                pp.x = px;
                pp.y = py;
                q.push(pp);
                dis[px][py] = dis[p.x][p.y] + 1;
                if(px == ed.x && py == ed.y)
                    break;
            }
        }
        if(dis[ed.x][ed.y] != -1) break;       //找到了，其他不用找了
    }
    printf("%d\n", dis[ed.x][ed.y]);
    return 0;
}
