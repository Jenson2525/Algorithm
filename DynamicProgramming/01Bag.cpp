//01背包的非递归版本
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MAX 100
using namespace std;
int n, W;  //物品数量、总重量
int w[MAX], v[MAX];  //物品的重量和价值
int dp[MAX + 1][MAX + 1];  //记忆化数组

void solve()
{
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j <= W; j++)
        {
            if(j < w[i])
                dp[i][j] = dp[i + 1][j];
            else    
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
        }
    }
    printf("%d", dp[0][W]);
}

int main()
{
    cin >> n >> W;
    for(int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    solve();
    return 0;
}