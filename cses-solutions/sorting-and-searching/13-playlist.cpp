#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin >> arr[i];

    map<int, int> curr;
    int ans = 0;

    int l=1, r=1;
    while(r<=n) {
        if(curr[arr[r]] == 0) curr[arr[r]] = r;
        else{
            while(l<= curr[arr[r]]){
                curr.erase(arr[l]);
                l++;
            }
            curr[arr[r]] = r;
        }

        ans = max(ans, r-l+1);
        r++;
    }
    cout << ans << '\n';
}

// keep a track of the last time a song was played in our current window.