//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int ans = INT_MIN;
        
        while(j < n){
            mp[fruits[j]]++;
            
            while(mp.size() > 2 && i < j){
                mp[fruits[i]]--;
                
                if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                    
                i++;
            }
            
            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends