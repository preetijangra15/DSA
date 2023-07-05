//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int* arr, int n, int i, int prev, int& sum, vector<vector<int>> &dp)
	{
	    if(i == n)
	        return 0;
	   
	   if(dp[i][prev+1] != -1)
	    return dp[i][prev+1];
	    
	   int pick = 0, notpick = 0;
	   
	   if(prev ==  -1 || arr[i] > arr[prev])
	    pick = arr[i] + solve(arr, n, i+1, i, sum, dp);
	    
	   notpick = solve(arr, n, i+1, prev, sum, dp);
	   
	    return dp[i][prev+1] = max(pick, notpick);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int sum = 0;
	    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	    return solve(arr, n, 0, -1, sum, dp);
	    
	    //return sum;
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends