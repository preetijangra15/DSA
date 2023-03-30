//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, vector<vector<int>>& mat, int n, vector<vector<int>>& dp)
    {
        if(i < 0 || i>= n || j < 0 || j>= n)
            return 0;
            
        //int up = 0, down = 0, dig = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int up = mat[i][j] + solve(i+1, j, mat, n, dp);
        int down = mat[i][j] + solve(i+1, j-1, mat, n, dp);
        int dig = mat[i][j] + solve(i+1, j+1, mat, n, dp);
        
        return dp[i][j] = max({up, down, dig});
    }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        
        //return solve(0, 0, mat, n);
        
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0;i<n;i++)
        {
            int res = solve(0, i, mat, n, dp);
            
            ans = max(res, ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends