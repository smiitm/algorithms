#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
 
    int  l=0, r=0;
    long long ans = 0, cs=0;
    while(r<n){
        cs += a[r];
        while(cs>=x){
            if(cs==x) ans++;
            cs -= a[l];
            l++;
        }
        r++;
    }
    cout << ans;
}
