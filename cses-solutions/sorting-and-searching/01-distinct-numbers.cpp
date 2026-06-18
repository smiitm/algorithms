#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n;

    set<int>s;
    for(int i=0;i<n;++i){
    	cin>>x;
    	s.insert(x);
    }
    cout<<s.size()<<endl;
}

// unordered_set uses hashing, default hash is exploitable by adversarial inputs, all elements land in one bucket, O(n2) TLE
// set uses Red-Black Tree, O(log n) per operation guaranteed, no hashing, nothing to exploit, always O(n log n) safe
// Fix: use unordered_set with custom splitmix64 hash (randomized seed) to prevent collision attacks