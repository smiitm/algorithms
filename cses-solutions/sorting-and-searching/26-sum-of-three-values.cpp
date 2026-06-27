#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++){
        cin >> a[i][0];
        a[i][1] = i+1;
    }
    sort(a.begin(), a.end());

    for(int i=0; i<n; ++i){
        int j=i+1, k=n-1;
        while(j<k){
            int s = a[i][0]+a[j][0]+a[k][0];
            if(s==t){
                cout << a[i][1] << " " << a[j][1] << " " << a[k][1];
                return 0;
            }
            else {
                if(s < t) j++;
                else k--;
            }
        }
    }

    cout << "IMPOSSIBLE";
}

// 3 sum lol