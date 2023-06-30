//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int findfirst(int nums[], int target, int n){
        int lo = 0, hi = n - 1;

        int res = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target){
                res = mid;
                hi = mid - 1;
            }

            else if(nums[mid] > target)
                hi = mid - 1;

            else
                lo = mid + 1;
        }

        return res;
    }
    int findlast(int nums[], int target, int n){
        int lo = 0, hi = n - 1;

        int res = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target){
                res = mid;
                lo = mid + 1;
            }

            else if(nums[mid] > target)
                hi = mid - 1;

            else
                lo = mid + 1;
        }

        return res;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int first = findfirst(arr, x, n);
	    int last = findlast(arr, x, n);
	    
	    //cout<<first<<" "<<last<<endl;
	    
	    if(first == -1 && last == -1)
	        return 0;
	        
	    return last - first + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends