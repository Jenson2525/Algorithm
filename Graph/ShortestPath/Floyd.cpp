#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX 100
#define INF (int)1e9
using namespace std;
int d[MAX][MAX];  //d[u][v]表示边e=(u, v)的权值（不存在时设为INF，不过时设为0）
int V, E;  //顶点数，边数
void Floyd()
{
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
}
int main()
{
    int s, t;
    cin >> V >> E;
    //初始化
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(i == j)
                d[i][j] = 0;
            else    
                d[i][j] = INF;
        }
    }
    for(int i = 0; i < E; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        d[x][y] = d[y][x] = w;  //无向图
    }
    Floyd();
    cin >> s >> t;  //输入起点和终点
    cout << d[s][t] << endl;
    return 0;
}