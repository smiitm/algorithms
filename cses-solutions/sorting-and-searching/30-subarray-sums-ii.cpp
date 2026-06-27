#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;

    map<ll,ll> psf;
    psf[0] = 1;

    ll ans=0, ps=0;

    for (int i=0; i<n; ++i) {
        ll a;
        cin >> a;

        ps += a;
        ans += psf[ps-x];
        psf[ps]++;
    }

    cout << ans;
}

// [l, r] is valid if ps[r] - ps[l-1] = x;
// so for each r we find number of l such that ps[l-1] = ps[r]-x
// its done using freq map of prefix sums