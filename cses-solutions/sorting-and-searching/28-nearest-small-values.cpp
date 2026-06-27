#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ai;
    stack<pair<int,int>> st;

    for (int i=0; i<n; ++i){
        cin >> ai;
        
        while(!st.empty() && st.top().first >= ai) st.pop();

        if(st.empty()) cout << 0 << " ";
        else cout << st.top().second+1 << " ";

        st.push({ai, i});
    }
}

// monotonic stack
// first of its kind