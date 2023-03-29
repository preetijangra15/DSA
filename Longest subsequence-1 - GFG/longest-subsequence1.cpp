//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n, int* arr, int i, int prev)
    {
        if(i >= n)
            return 0;
            
        int pick = 0, notpick = 0;
        
        if(prev == -1 || abs(arr[i] - arr[prev]) == 1)
            pick = 1 + solve(n, arr, i+1, i);
            
        notpick = solve(n, arr, i+1, prev);
        
        return max(pick, notpick);
    }
    int longestSubsequence(int n, int arr[])
    {
        // code here
        return solve(n, arr, 0, -1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends