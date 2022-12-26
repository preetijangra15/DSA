//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int i = 0;
        int *ans = new int[2];
        //cout<<"hi"<<endl;
        while(i<n)
        {
            int correct = arr[i] -1;
            
            if(arr[i] != arr[correct])
                swap(arr[i], arr[correct]);
                
            else
                i++;
            // for(int k= 0;k<n;k++)
            //     cout<<arr[k]<<" ";
                
            // cout<<endl;
        }
        
        for(int j=0;j<n;j++)
        {
            if(arr[j] != j+1)
            {
                ans[0] = arr[j];
                ans[1] = j+1;
                
                //cout<<arr[j]<<" "<<j+1<<endl;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends