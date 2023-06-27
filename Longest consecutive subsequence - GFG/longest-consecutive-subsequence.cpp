//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
        int count = 1, ans = 1;
        sort(arr, arr+n);
        
        for(int i=0;i<n-1;i++)
        {
            while(arr[i+1] == arr[i])
                i++;
                
            if(arr[i+1] == (arr[i] + 1))
            {
                count++;
                ans = max(ans, count);
            }
            
            else
                count = 1;
        }
     
        return ans;
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends