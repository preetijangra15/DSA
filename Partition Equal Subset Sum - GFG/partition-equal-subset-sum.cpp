//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool solve(int n, int* arr, int sum, int i)
    {
        if(sum == 0)
            return true;
            
        if(sum < 0 || i >= n)
            return false;
            
        return (solve(n, arr, sum - arr[i], i+1) || solve(n, arr, sum, i+1));
    }
    
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i =0;i<n;i++)
            sum += arr[i];
            
        if(sum%2 != 0)
            return 0;
            
        return solve(n, arr, sum/2, 0);
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