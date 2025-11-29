//smiit
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        string str = to_string(i);
        for (char c : str) {
            int digit = c - '0';
            if (digit > 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - digit]);
            }
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}

// min oprations among numbers after subtracting a digit.
// dp[i] = min(dp[i - digit]) + 1 for all digits in i