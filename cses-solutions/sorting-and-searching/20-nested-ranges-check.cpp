#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> ranges(n, vector<int>(3));
    for(int i = 0; i < n; ++i){
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }

    vector<int> contains(n), contained(n);

    sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    int maxe = 0;
    for (int i=0; i<n; ++i) {
        if (maxe >= ranges[i][1]) contained[ranges[i][2]] = 1;
        maxe = max(maxe, ranges[i][1]);
    }

    int mine = INT_MAX;
    for(int i=n-1; i>=0; --i){
        if(mine <= ranges[i][1]) contains[ranges[i][2]] = 1;
        mine = min(mine, ranges[i][1]);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << " ";
    cout << '\n';
    for (int i = 0; i < n; i++) cout << contained[i] << " ";
    return 0;
}

// sort by increasing start and decreasing end (if start are same)
// if for a range there is some range with start <= and end >=, then its contained.
// if for a range there is some range whose start is >= and end is <=, then it contains.
// draw some ranges to understand better.