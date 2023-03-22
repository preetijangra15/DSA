//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int solve(vector<int>& price, int i, int n, bool flag, int k, vector<vector<int>>& memo)
{
    if(i == n || k == 0)
        return 0;
        
    int take = 0, notake = 0;
    if(memo[i][k] != -1)
        return memo[i][k];
        
    if(flag == true)
        take += -price[i] + solve(price, i+1, n, false, k-1, memo);
        
    else 
        take += price[i] + solve(price, i+1,n,true,k-1, memo);
        
    notake = solve(price, i+1, n, flag, k, memo);
    
    return memo[i][k] = max(take, notake);
}
int maxProfit(vector<int>&price){
    //Write your code here..
    vector<vector<int>> memo(price.size(),vector<int>(5,-1));
    int n = price.size();
    return solve(price, 0, n, true, 4, memo);
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