#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    long long d = 0, sd = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> d;
        sd += d;
    }

    sort(a.begin(), a.end());
    long long sf=0;
    for(int i=0; i<n; ++i) sf += 1LL*a[i]*(n-i);

    cout << sd-sf << '\n';
}

// total reward is sum of (d-f) over all tasks
// we need to minimise sum of f, do shorter tasks first