//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int arr[], int n, int sum, int i, vector<vector<int>>& dp){
        if(sum == 0)
            return true;
            
        if(i >= n || sum < 0)
            return false;
        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        bool ans = solve(arr, n, sum-arr[i], i+1, dp);
        bool ans1 = solve(arr, n,sum, i+1, dp);
        
        return dp[i][sum] = (ans||ans1);
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i =0;i < n;i++)
            sum += arr[i];
            
        if(sum%2 != 0)
            return false;
            
        sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(arr, n, sum, 0, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends