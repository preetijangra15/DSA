//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<k;i++)
            mp[arr[i]]++;
        
        // for(auto x:mp)
        //     cout<<x.first<<" "<<x.second<<endl;
        
        ans.push_back(mp.size());
        int j = 0;
        
        for(int i = k;i<n;i++)
        {
            mp[arr[i]]++;
            
            mp[arr[j]]--;
            if(mp[arr[j]] == 0)
                mp.erase(arr[j]);
            j++;
            
            
             
            //cout<<i<<endl;
            
            
            ans.push_back(mp.size());
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends