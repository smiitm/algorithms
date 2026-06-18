#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent;
    
    public:
        DSU(int n){
            rank.resize(n);
            parent.resize(n);
            
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        
        int find(int i) {
            if(parent[i] == i) return i;
            return (parent[i] = find(parent[i]));
        }
        
        void unite(int x, int y) {
            int s1 = find(x), s2 = find(y);
            if (s1 != s2) {
                if (rank[s1] < rank[s2]) parent[s1] = s2;
                else if (rank[s1] > rank[s2]) parent[s2] = s1;
                else parent[s2] = s1, rank[s1]++;
            }
        }
};