//最长公共子序列
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MAX 100
using namespace std;
int n, m;  
char s[MAX], t[MAX];  
int dp[MAX][MAX];  //记忆化数组

void solve()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    printf("%d", dp[n][m]);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int j = 0; j < m; j++)
        cin >> t[j];
    solve();
    return 0;
}
