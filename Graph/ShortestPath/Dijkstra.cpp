#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define MAX 100
#define INF 1e9
using namespace std;
//first是最短距离，second是顶点的编号
typedef pair<int, int> P;  
struct edge
{
    int to;
    int cost;
};
int V, E;  //顶点的个数，边的个数
vector<edge> G[MAX];  //图
int d[MAX];  //最短距离

void Dijkstra(int s)
{
    //通过指定的greater<P>参数，堆按照first从小到大的顺序取出值
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d + 1, d + V + 1, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
int main()
{
    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    Dijkstra(1);
    for(int i = 1; i <= V; i++)
        cout << d[i] << " ";
    return 0;
}