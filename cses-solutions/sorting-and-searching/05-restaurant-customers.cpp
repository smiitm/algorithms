#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int, int>> e(2*n);
    
    for(int i = 1; i <= n; ++i) {
        int a, d;
        cin >> a >> d;
        e[2*i-2] = {a, 0};
        e[2*i-1] = {d, 1};
    }

    sort(e.begin(), e.end());

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < 2*n; ++i) {
        if(e[i].second == 0) cnt++;
        else cnt--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

// event based sorting