/*
二分图判定
给定一个具有n个顶点的图。
要给图上每个顶点染色，并且要使相邻的顶点颜色不同。
是否能最多用2种颜色进行染色？
*/
#include<iostream>
#include<cstdio>
#include<vector>
#define MAX_V 1010
using namespace std;
vector<int> G[MAX_V];  //图
int V, E;  //顶点数，边数
int color[MAX_V];  //顶点i的颜色(1或-1)

//深度优先搜索，把顶点染成1或-1
bool dfs(int v, int c)
{
    color[v] = c;  //把顶点v染成c
    for(int i = 0; i < G[v].size(); i++)
    {
        //如果相邻的顶点同色，则返回false
        if(color[G[v][i]] == c)
            return false;
        //如果没被染色，则染成-c
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c))
            return false;
    }
    //如果所有顶点都染过色了，则返回true
    return true;
}
void solve()
{
    for(int i = 0; i < V; i++)
    {
        if(color[i] == 0)
        {
            if(!dfs(i, 1))
            {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main()
{
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    solve();
    return 0;
}
