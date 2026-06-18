#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(100000, INT_MAX);
        pq.push({0, start});
        
        while(!pq.empty()){
            pair<int,int> current = pq.top();
            pq.pop();
            int steps = current.first;
            int num = current.second;

            for(int &a : arr){
                int temp = (num*a)%100000;
                cout << "num: " << num << ", a: " << a << ", temp: " << temp << ", steps: " << steps << endl;
                if(temp==end) return steps+1;
                if(dist[temp] > steps+1){
                    dist[temp] = steps+1;
                    pq.push({steps+1, temp});
                }
            }
        }
        
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;
    cout << sol.minimumMultiplications(arr, start, end) << endl; // Output: 2
    return 0;
}