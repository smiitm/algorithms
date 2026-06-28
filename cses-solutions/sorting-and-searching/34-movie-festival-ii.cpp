#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> movies(n);
    for (int i = 0; i < n; ++i) cin >> movies[i].second >> movies[i].first;
    sort(movies.begin(), movies.end());

    multiset<int> curr;
    for (int i = 0; i < k; ++i) curr.insert(0);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int start = movies[i].second, end = movies[i].first;

        auto it = curr.upper_bound(start);
        if (it != curr.begin()) {
            --it;
            curr.erase(it);
            curr.insert(end);
            ans++;
        }
    }
    cout << ans << '\n';
}

// pick the tightest fit — the member who finished latest but still before this movie starts. 
// this preserves early-finishing members for movies with early starts.