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
        if(a[i] > ans + 1) break;
        ans += a[i];
    }

    cout << ans + 1 << '\n';
}

// if coins till index i can make till value x
// then coins till index i+1 can make till value x + a[i+1] if(a[i+1] <= x + 1).