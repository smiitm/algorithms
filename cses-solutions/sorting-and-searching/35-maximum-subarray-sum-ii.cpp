#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i)  cin >> arr[i];
    
    vector<long long> ps(n+1);
    multiset<long long> w;
    ps[0] = 0;
    long long ans=LLONG_MIN;
    for (int i = 1; i <= n; ++i){
        ps[i] = ps[i-1] + arr[i];

        // no valid subarrays of sz >= a
        if(i<a) continue;

        w.insert(ps[i-a]);

        // discard subarrays with sz > b ending at i
        if(i>b) w.erase(w.find(ps[i-b-1]));

        ans = max(ans, ps[i]-*w.begin());
    }
    cout << ans << '\n';
}

// the max sum for a subarray ending at i is ps[i] - min(ps[i-a]....ps[i-b])