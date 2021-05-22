#include<iostream>
#include<cstdio>
#define MAX 100
#define INF 1e9
using namespace std;
//从顶点from指向顶点to的权值为cost的边
struct edge
{
    int from;
    int to;
    int cost;
};
edge e[MAX];  //边
int d[MAX];  //最短距离
int V, E;  //顶点数、边数
//求最短距离
void BellmanFord(int s)
{
    for(int i = 1; i <= V; i++)
        d[i] = INF;
    d[s] = 0;
    while(true)
    {
        bool update = false;  //标记
        for(int i = 1; i <= E; i++)
        {
            edge tmp = e[i];
            if(d[tmp.from] != INF && d[tmp.to] > d[tmp.from] + tmp.cost)
            {
                d[tmp.to] = d[tmp.from] + tmp.cost;
                update = true;
            }    
        } 
        if(!update)
            break;
    }
}
int main()
{
    cin >> V >> E;
    for(int i = 1; i <= E; i++)
        cin >> e[i].from >> e[i].to >> e[i].cost;
    BellmanFord(1);  //从起点出发
    for(int i = 1; i <= V; i++)
        cout << d[i] << " ";
    return 0;   
}