//smiit
#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;

int main() {
    int n;
    cin >> n;
    
    vector<vector<bool>> grid(n+1, vector<bool>(n+1, true));
    string temps;
    for(int i=1; i<=n; i++){
        cin >> temps;
        for(int j=1; j<=n; j++){
            grid[i][j] = (temps[j-1] == '.');
        }
    }

    if(!grid[1][1] || !grid[n][n]) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i-1][j]) dp[i][j] = (dp[i][j] + dp[i-1][j])%M;
            if(grid[i][j-1]) dp[i][j] = (dp[i][j] + dp[i][j-1])%M;
        }
    }

    cout << dp[n][n] << endl;
    return 0;
}

// paths to reach (i,j) = paths to reach (i-1,j) + paths to reach (i,j-1) (if walkable).
// dp[i][j] = (if not *) dp[i-1][j] + (if not *) dp[i][j-1].
// if start or end is blocked, print 0.