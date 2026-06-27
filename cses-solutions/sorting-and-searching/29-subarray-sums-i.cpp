#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    map<long long, long long> psf;
    psf[0] = 1;

    long long ans = 0, ps = 0;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        ps += a;
        ans += psf[ps - x];
        psf[ps]++;
    }

    cout << ans;
}
