//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        for(auto i:mp)
        {
            ans.push_back(i.second);  
        }
        sort(ans.begin(),ans.end());
        int i=0;int n=ans.size();
        while(k>0)
        {
            if(ans[n-1]>=ans[n-2])
            {
                ans[n-1]=ans[n-1]-1;
                k--;
                sort(ans.begin(),ans.end());
            }
        }
        int final=0;
        for(int i=0;i<n;i++)
        {
            final=final+ans[i]*ans[i];
        }
        return final;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends