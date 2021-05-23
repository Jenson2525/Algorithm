//01背包的递归版本
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MAX 100
using namespace std;
int n, W;  //物品数量、总重量
int w[MAX], v[MAX];  //物品的重量和价值
int dp[MAX][MAX];  //记忆化数组

//记忆化搜索，开始挑选
int rec(int i, int j)
{
    //已经计算过的就用之前的数组
    if(dp[i][j] >= 0)
        return dp[i][j];
    int res;
    if(i == n)
        res = 0;  //没有剩余的物品
    else if(j < w[i])
        res = rec(i + 1, j);  //无法挑选这个物品
    else    
        //挑选和不挑选都尝试一下
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    return dp[i][j] = res;
}
void solve()
{
    //初始化
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, W));
}

int main()
{
    cin >> n >> W;
    for(int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    solve();
    return 0;
}