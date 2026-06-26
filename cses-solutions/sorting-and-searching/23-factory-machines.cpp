#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll check(vector<int>& mach, ll time) {
    ll cnt = 0;
    for (int k : mach) cnt += time / k;
    return cnt;
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> mach(n);
    int mink = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> mach[i];
        mink = min(mink, mach[i]);
    }

    ll l = 0, r = 1LL*t*mink, ans = r+1;

    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (check(mach, m) >= t) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << ans << '\n';
}

// bs on answer