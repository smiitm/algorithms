#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> pos(n + 2);
    vector<int> arr(n + 2);
    pos[0] = 0; pos[n+1] = n+1;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    long long ans = 1;
    for (int i = 2; i <= n; i++) if(pos[i] < pos[i - 1]) ans++;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        
        int x=arr[a], y=arr[b];
        if(x == y+1) ans--;
        if(y == x+1) ans++;
        if(pos[x-1] > a && pos[x-1] < b) ans--;
        if(pos[y-1] > a && pos[y-1] < b) ans++;
        if(pos[x+1] > a && pos[x+1] < b) ans++;
        if(pos[y+1] > a && pos[y+1] < b) ans--;

        cout << ans << '\n';
        swap(arr[a], arr[b]);
        pos[x] = b; pos[y] = a;
    }
}

// if an x appears before an x-1, we need to start a new round.
// we find intial ans, and delta on every swap