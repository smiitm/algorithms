#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<int>> stays(n, vector<int> (3));
    for(int i=0; i<n; ++i){
        cin >> stays[i][0] >> stays[i][1]; 
        stays[i][2] = i;
    }

    sort(stays.begin(), stays.end());

    int rooms = 1;
    vector<int> ans(n);
    set<pair<int, int>> curr;

    curr.insert({stays[0][1], 1});
    ans[stays[0][2]] = 1;
    
    for (int i = 1; i < n; ++i){
        if (curr.begin()->first < stays[i][0]) {
            ans[stays[i][2]] = curr.begin()->second;
            curr.insert({stays[i][1], ans[stays[i][2]]});
            curr.erase(curr.begin());
        } else{
            rooms++;
            ans[stays[i][2]] = rooms;
            curr.insert({stays[i][1], rooms});
        }
    }
    
    cout << rooms << "\n";
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    return 0;
}

// we need to assign a room at arrival, sort by arrival
// if any room is empty assign it, else start new