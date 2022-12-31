//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        
        unordered_map<int, int> m;
        
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        
        vector<int> ans;
        
        // for(int i=0;i<n;i++)
        // {
        //     if(m[arr[i]] > 1)
        //     {
        //         ans.push_back(arr[i]);
        //         m[arr[i]] = 1;
        //     }
        // }
        
        for(auto x:m)
        {
            if(x.second > 1)
                ans.push_back(x.first);
        }
        sort(ans.begin(), ans.end());
        if(ans.size() > 0)
            return ans;
        
        
        return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends