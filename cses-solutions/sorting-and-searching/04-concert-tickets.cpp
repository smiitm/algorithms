#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    multiset<long long> a;
    
    for(int i = 0; i < n; ++i) {
        long long price;
        cin >> price;
        a.insert(price);
    }
    
    for(int i=0;i<m;++i) {
        long long b;
        cin >> b;

        auto it = a.upper_bound(b);

        if (it == a.begin()) cout << -1 << endl;
        else {
            --it;
            cout << *it << endl;
            a.erase(it);
        }
    }
}

// just implementation of whats asked
// vector cant be used because we need to remove elements, its O(n)

