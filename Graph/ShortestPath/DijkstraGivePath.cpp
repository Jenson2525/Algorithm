#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define INF 1e9
#define MAX 100
using namespace std;
int cost[MAX][MAX];  //codt[u][v]表示边e=(u,v)的权值（不存在时设为INF）
int d[MAX];  //顶点s出发的最短距离
bool used[MAX];  //已经使用过的图
int pre[MAX];  //最短路上的前驱节点
int V, E;  //顶点数，边数

//初始化cost
void init()
{
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cost[i][j] = INF;   
}

//求从起点s出发到各个顶点的最短距离
void Dijkstra(int s)
{
    //初始化
    fill(d, d + V, INF);
    fill(used, used + V, false);
    fill(pre, pre + V, -1);
    d[s] = 0;

    while(true)
    {
        int v = -1;
        for(int u = 0; u < V; u++)
        {
            if(!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }
        if(v == -1)
            break;
        used[v] = true;
        for(int u = 0; u < V; u++)
        {
            if(d[u] > d[v] + cost[v][u])
            {
                d[u] = d[v] + cost[v][u];
                pre[u] = v;
            }
        }
    }
}

//到顶点t的最短路
vector<int> GetPath(int t)
{
    vector<int> path;
    for(; t != -1; t = pre[t])
        path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}
int main()
{
    int s, t;
    cin >> V >> E;
    init();
    for(int i = 1; i <= E; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        cost[x][y] = w;
    }
    cout << "Please input the start and the terminal:" << endl;
    cin >> s >> t;
    Dijkstra(s);
    cout << "The path is: " << endl;
    vector<int> vec = GetPath(t);
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
    {
        if(it != vec.end() - 1)
            cout << *it << "->"; 
        else
            cout << *it;
    }
    return 0;
}
