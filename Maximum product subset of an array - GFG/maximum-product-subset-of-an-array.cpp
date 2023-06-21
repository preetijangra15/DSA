//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
     int m=1e9+7;
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        if(n==1) return a[0];
        int mi=INT_MIN;
        int c=0;
        int z=0;
        long long int ans=1;
        for(int i=0;i<n;i++){
           if(a[i]!=0){
               ans=(ans%m*a[i]%m)%m;
           }
           if(a[i]==0){
               z++;
           }
           if(a[i]<0){
               c++;
               mi=max(mi,a[i]);
           }
        }
        if(z==n) return 0;
        if(c%2==0) return ans%m;
        if(c%2==1){
            if(c==1 && z>0 && c+z==n) return 0;
            else return (ans/mi)%m;
        }
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends