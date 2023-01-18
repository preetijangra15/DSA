//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    
    bool isvalid(int A[], int N, int M, int max)
    {
        int student =1;
        int sum =0;
        
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            
            if(sum>max)
            {
                student +=1;
                sum = A[i];
            }
              
            //cout<<"students "<<student<<endl; 
            if(student >M)
                return false;
                
        }
        
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M)
            return -1;
            
        int high = 0;
        
        for(int i=0;i<N;i++)
            high += A[i];
            
        int res=-1;
        int low = A[N-1];
        
        //cout<<low<<" "<<high<<endl;
        while(low<=high)
        {
            //cout<<mid<<endl;
            
            int mid = low + (high-low)/2;
            //cout<<mid<<endl;
            //cout<<isvalid(A,N,M, mid)<<endl;
            if(isvalid(A,N,M, mid) == true)
            {
                
                res = mid;
                high = mid-1;
            }
            
            else
                low = mid+1;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends