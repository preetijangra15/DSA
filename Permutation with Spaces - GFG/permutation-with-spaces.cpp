//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void solve(int i,string s, vector<string> &ans, int n, string res)
    {
        if(i == n)
        {
            res.push_back(s[i]);
            ans.push_back(res);
            return;
        }
        
        string op = res;
        string op1 = res;
        
        op.push_back(s[i]);
        op1.push_back(s[i]);
        op1.push_back(' ');
        
        solve(i+1, s, ans, n, op);
        solve(i+1, s, ans, n, op1);
        
    }
    vector<string> permutation(string S){
        // Code Here
        vector<string> ans;
        
        solve(0, S, ans, S.length()-1,"");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends