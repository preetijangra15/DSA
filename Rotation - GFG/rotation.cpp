//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int findmin(int arr[], int n){
        if(n == 1)
            return 0;
            
        int lo = 0, hi = n-1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            int prev = (mid + n - 1)%n;
            int next = (mid + 1)%n;
            
            if(arr[mid] < arr[prev] && arr[mid] < arr[next])
                return mid;
                
            else if(arr[hi] < arr[mid])
                lo = mid + 1;
                
            else
                hi = mid - 1;
        }
        
        return -1;
    }
	int findKRotation(int arr[], int n) {
	    // code here
	    
	    int ans = findmin(arr, n);
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends