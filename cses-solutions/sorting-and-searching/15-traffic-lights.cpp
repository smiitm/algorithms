#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> ls;
    multiset<int> segs;

    ls.insert(0);
    ls.insert(x);
    segs.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto it = ls.upper_bound(p);
        int r = *it;
        int l = *prev(it);

        segs.erase(segs.find(r - l));

        segs.insert(p-l);
        segs.insert(r-p);

        ls.insert(p);

        cout << *segs.rbegin() << " ";
    }

    cout << '\n';
}

// track segments and update with every new light
// each time longest seg will only reduce or stay same