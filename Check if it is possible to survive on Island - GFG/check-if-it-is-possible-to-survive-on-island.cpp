//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int s, int n, int m){
        // code here
        int ans=0;
        int buy= s-s/7;
        if((s*m)%n==0)
            ans= (s*m)/n;
        else
            ans= (s*m)/n +1;
        if(ans<=buy)
            return ans;
        else
            return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends