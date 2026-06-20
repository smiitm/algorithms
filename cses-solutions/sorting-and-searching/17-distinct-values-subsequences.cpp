#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n+1);
    map<int, int> cnt;
    int x;
    for(int i=0; i<n; ++i){
        cin >> x;
        cnt[x]++;
    }

    long long ans = 1;
    for(auto [k, v] : cnt) ans = (ans * (v+1))%M;

    cout << (ans - 1 + M) % M << '\n';
    return  0;
}

// for all unique elms that exist in the array, we can either take one occurence or none.
// so the ans = product of (cnt+1) over all unique elms
// remove the empty subsequence