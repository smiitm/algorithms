#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0, mx = 0, x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    cout << max(sum, 2*mx) << '\n';
}