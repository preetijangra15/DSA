//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int i, int j, string &s, string& t, vector<vector<int>> &dp)
  {
      if(i < 0) return j+1;
      if(j < 0) return i+1;
      
      int match = INT_MAX, del = INT_MAX, ins = INT_MAX, rem = INT_MAX;
     
     if(dp[i][j] != -1)
        return dp[i][j];
        
    if(s[i] == t[j]) 
        match = 0 + solve(i-1, j-1, s,t,dp);
        
    else
    {
        del = 1 + solve(i-1, j, s,t,dp);
        ins = 1+ solve(i, j-1, s, t,dp);
        rem = 1+ solve(i-1, j-1, s, t,dp);
    }
    
    return dp[i][j] =  min({match, del, ins, rem});
  }
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends