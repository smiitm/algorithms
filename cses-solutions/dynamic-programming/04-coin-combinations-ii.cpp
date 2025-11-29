// smiit
#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= x; ++i)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            long long without = dp[i - 1][j];
            long long with = (j >= coins[i] ? dp[i][j - coins[i]] : 0);
            dp[i][j] = (without + with) % M;
        }
    }
    cout << dp[n][x] << "\n";
    return 0;
}

// dp[i][j] represents the number of ways to make sum j using the first i coins.
// For each dp[i][j], we can either include coin[i] or not.
// If we don't include coin[i], the number of ways to reach sum j is dp[i-1][j].
// If we include coin[i], we add the number of ways to reach (j - coin[i]) using the same coin set is dp[i][j - coin[i]].
