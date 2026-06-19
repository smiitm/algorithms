#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }

    long long ans = 1;

    for (int i = 1; i < n; i++) if(p[i] < p[i - 1]) ans++;

    cout << ans << '\n';
}

// if an x appears before an x-1, we need to start a new round.