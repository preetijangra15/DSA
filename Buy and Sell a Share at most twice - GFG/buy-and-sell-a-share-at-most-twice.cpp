//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int solve(vector<int>& price, int n, int i, int k, bool flag, vector<vector<int>>& dp)
{
    if(i == n || k == 0)
        return 0;
    
    if(dp[i][k] != -1)
        return dp[i][k];
        
    int pick = INT_MIN, notpick = INT_MIN;
    
    if(flag)
     pick = -price[i] + solve(price, n, i+1, k-1, !flag, dp);
     
    if(!flag)
        pick = price[i] + solve(price, n, i+1, k-1, !flag, dp);
        
    notpick = solve(price, n, i+1, k, flag, dp);
    
    return dp[i][k] = max(pick, notpick);
}

int maxProfit(vector<int>&price){
    //Write your code here
    
    int n = price.size();
    vector<vector<int>> dp(n+1, vector<int>(5, -1));
    
    return solve(price, n, 0, 4, true, dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends