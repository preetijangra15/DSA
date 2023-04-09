//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int arr[], int n, int k)
    {
        // Write Your Code here
        int ansmin = 0, ansmax = 0;
        sort(arr, arr+n);
        int i=0, j = n-1;
        
        while(i <= j)
        {
            ansmin += arr[i];
            i++;
            j -= k;
        }
        
        i = 0;
        j = n-1;
        
        while(i <= j)
        {
            ansmax += arr[j];
            i+=k;
            j--;
        }
        
        return {ansmin, ansmax};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends