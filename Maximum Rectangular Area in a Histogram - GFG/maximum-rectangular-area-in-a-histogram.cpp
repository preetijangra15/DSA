//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    void findminpre(vector<long long>& v, long long arr[], int n){
        stack<long long> st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            while(st.top() != -1 && arr[i] <= arr[st.top()])
                st.pop();
                
            v.push_back(st.top());
            st.push(i);
        }
        
        return;
    }
    void findminsuff(vector<long long>& v, long long arr[], int n){
        stack<long long> st;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && arr[i] <= arr[st.top()])
                st.pop();
                
            v.push_back(st.top());
            st.push(i);
        }
        
        return;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> pre;
        vector<long long> suff;
        
        findminpre(pre, arr, n);
        findminsuff(suff, arr, n);
        reverse(suff.begin(), suff.end());
        
        
        // for(int i=0;i<n;i++)
        //     if(pre[i] == -1)
        //         pre[i] = 0;
                
        for(int i = n-1;i>=0;i--)
            if(suff[i] == -1)
                suff[i] = n;
                
                
        long long ans= LONG_MIN;
        for(int i = 0;i < n;i++)
        {
            long long temp = arr[i] *abs(suff[i] - pre[i] - 1);
            
            ans = max(ans, temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends