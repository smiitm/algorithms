#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // store all pair sums
    set<tuple<int, int, int>> ps;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j) ps.insert({a[i]+a[j], i, j});
    }

    // we will iterate over i, j to find k, l for pair sums
    for(int i=0; i<n; ++i){
        // remove pairs such that i or j are not in pair sums
        for(int x=i+1; x<n; ++x) ps.erase({a[i]+a[x], i, x});

        for(int j=i-1; j>=0; --j){
            int r = t - a[i] - a[j];

            auto it = ps.lower_bound({r, -1, -1});
            if(it == ps.end()) continue;

            auto [s, k, l] = *it;
            if(s != r) continue;

            cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}