//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &arr,  int n, vector<int> &v)
    {
        if(i == n)
        {
            ans.push_back(v);
            return;
        }
        
        vector<int> v1 = v;
        vector<int> v2 = v;
        
        v2.push_back(arr[i]);
        
        
        solve(i+1,arr,n,v2);
        solve(i+1,arr,n,v1);
    }
    vector<vector<int> > subsets(vector<int>& arr)
    {
        //code here
        
        
        vector<int> v;
        solve(0,arr, arr.size(),v);
        sort(ans.begin(), ans.end());
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
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends