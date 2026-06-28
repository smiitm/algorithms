#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    map<ll,ll> psf;
    psf[0] = 1;

    ll ans=0, ps=0;

    for (int i=0; i<n; ++i) {
        ll a;
        cin >> a;
        ps += a;

        ll r = ((ps%n)+n)%n;
        ans += psf[r];
        psf[r]++;
    }

    cout << ans;
}

// subarray sums II with slight change only
// remainders in cpp can be negative