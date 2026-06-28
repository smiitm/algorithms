#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    map<ll,ll> f;
    ll ans=0, l=0;
    for (int r=0; r<n; ++r){
        f[a[r]]++;
        while((int)f.size()>k){
            f[a[l]]--;
            if(f[a[l]]==0) f.erase(a[l]);
            l++;
        }
        ans += r-l+1;
    }

    cout << ans;
}

// somewhat similar to subarray sum I