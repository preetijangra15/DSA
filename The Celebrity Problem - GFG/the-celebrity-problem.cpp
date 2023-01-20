//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //int arr[n];
        
        int ans = -1;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            bool cel = true;
            
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                    
                if(M[i][j] == 1)
                {
                    cel = false;
                    break;
                }
                
            }
            if(cel == true)
                {
                    count++;
                    ans = i;
                }
        }
        
        
            
        if(count >  1)
            return -1;
                
                
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends