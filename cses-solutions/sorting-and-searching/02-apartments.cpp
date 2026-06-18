#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;

    vector<long long> a(n),b(m);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ans = 0;
    int ap = 0;
    for(int i=0;i<n;++i){
    	while(ap<m && b[ap]<a[i]-k) ap++;
    	if(ap<m && abs(a[i]-b[ap])<=k){
            ans++;
            ap++;
        }
        if(ap>=m) break;
    }

    cout<<ans<<endl;
}

// greedy approach
// assign minimum possible apartment to each applicant