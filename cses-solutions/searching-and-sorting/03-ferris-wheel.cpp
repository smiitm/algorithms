#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;

    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    sort(a.begin(),a.end());

    int ans = 0;
    int l = 0, r = n - 1;
    while(l < r){
        if(a[l] + a[r] <= x){
            ans++;
            l++; r--;
        }
        else{ ans++; r--;}
    }
    if(l == r) ans++;
    cout<<ans<<endl;
}

// greedy approach
// put fattest and thinnest together, if they cant fit, fattie takes whole gondola
// thin kid can still go with lighter fattie