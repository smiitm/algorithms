#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = LLONG_MIN;
    long long cnt = 0;
    long long x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt += x;
        ans = max(ans, cnt);
        if (cnt < 0) cnt = 0;
    }

    cout << ans << '\n';
}

// Kadane's algorithm
// using int would give WA due to overflow