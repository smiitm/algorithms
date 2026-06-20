#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i=1; i<=n; ++i) cin>>a[i];

    long long ans = 0;
    map<int, int> curr;
    int l = 1, r = 1;

    while (r <= n) {
        l = max(l, curr[a[r]] + 1);
        ans += r - l + 1;
        curr[a[r]] = r;
        r++;
    }

    cout << ans << '\n';
    return  0;
}

// sliding window with unique elements only
// if there are no repetations between l to r, all [l,r], [l+1,r]... [r, r] are valid which is r-l+1 number of subarrays.
// if there while expanding we encounter repetation, we move l past the first occurence of our new element.