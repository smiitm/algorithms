#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<int>& a, ll m, ll k) {
    ll cs = 0;
    ll ps = 1;
    for(int i : a){
        if(i > m) return false;
        if(cs+i<=m) cs+=i;
        else{
            cs = i;
            ps++;
            if (ps > k) return false;
        }
    }
    
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    
    for (int i=0; i<n; ++i) cin >> a[i];
    
    ll l = *max_element(a.begin(), a.end());
    ll r = accumulate(a.begin(), a.end(), 0LL);
    ll ans = r+1;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (check(a, m, k)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << ans << '\n';
}

// bs on answer