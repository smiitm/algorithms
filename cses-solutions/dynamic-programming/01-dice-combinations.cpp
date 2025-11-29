//smiit
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
 
int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
 
    for (int i = 1; i <= n; ++i) {
        for (int dice = 1; dice <= 6; ++dice) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }
 
    cout << dp[n] << endl;
    return 0;
}

// we can reach i sum from getting 1 to 6 on the last die.
// dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]