#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a});
    }

    sort(movies.begin(), movies.end());

    int le = 0;
    int ans = 0;

    for (auto [end, start] : movies) {
        if (start >= le) {
            ans++;
            le = end;
        }
    }

    cout << ans << '\n';
    return 0;
}

// greedy approach
// first ending movie is always optimal