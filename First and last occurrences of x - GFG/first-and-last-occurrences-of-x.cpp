//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    
    /////Linear search////
    // int first = INT_MAX, last = INT_MIN;
    // bool flag = false;
    // for(int i = 0; i < n;i++)
    // {
    //     if(arr[i] == x)
    //     {
    //         flag = true;
    //         first = min(first, i);
    //         last = max(last, i);
    //     }
        
    // }
    // if(flag)
    //     return {first, last};
        
    // else
    //     return {-1, -1};
    
    
    int hi = n-1, lo = 0;
    int first = -1;
    while(lo <= hi){
        
        int mid = (lo+hi)/2;
        
        if(arr[mid] == x)
        {
            first = mid;
            hi = mid - 1;
        }
        
        else if(arr[mid] < x)
        {
            lo = mid+1;
        }
        
        else
            hi = mid - 1;
        
    }
    
    
    lo = 0, hi = n-1;
    int last = -1;
     while(lo <= hi){
        
        int mid = (lo+hi)/2;
        
        if(arr[mid] == x)
        {
            last = mid;
            lo = mid + 1;
        }
        
        else if(arr[mid] < x)
        {
            lo = mid+1;
        }
        
        else
            hi = mid - 1;
        
    }
    
    return {first, last};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends