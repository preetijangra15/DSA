//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int solve(string s, string str, int n, int i, int j, vector<vector<int>>& dp)
    {
        if( i == n || j == n)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int pick = INT_MIN, notpick = INT_MIN;
        
        if(s[i] == str[j])
        {
            pick = 1 + solve(s, str, n, i+1, j+1, dp);
        }
        else
            notpick = max(solve(s, str, n, i+1, j, dp), solve(s, str, n, i, j+1, dp));
        
        return dp[i][j] = max(pick, notpick);
    }
    int longestPalinSubseq(string s) {
        //code here
        
        string str = s;
        reverse(str.begin(), str.end());
        
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(s, str,n, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends