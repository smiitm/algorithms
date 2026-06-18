#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - a[n / 2]);
    }

    cout << ans << '\n';
}

// median minimizes the sum of absolute differences.
// think of what happens when you move from median to the left or right.