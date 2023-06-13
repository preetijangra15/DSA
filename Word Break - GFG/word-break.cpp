//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(int id, string& A, vector<string>& B)
    {
        // string ans = "";
        
        // if(id >= A.size())
        //     return 1;
            
        // for(int i = id; i < A.size(); i ++)
        // {
        //     ans += A[i];
            
        //     if(find(B.begin(), B.end(), ans) != B.end())
        //     {
        //         if(1 && solve(i+1, A, B))
        //             return true;
        //     }
        // }
        
        // return 0;
        
        string ans = "";
        
        if(id >= A.size())
            return 1;
        
        for(int i = id; i< A.size(); i++)
        {
            ans += A[i];
            if(find(B.begin(), B.end(), ans) != B.end())
            {
                if(1 && solve(i+1, A, B))
                    return true;
            }
        }
        
        return false;
        
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        return solve(0, A, B);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends