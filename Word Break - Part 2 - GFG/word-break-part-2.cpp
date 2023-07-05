//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void solve(unordered_map<string,int> mp, string s,vector<string>& ans,string temp,string temp2,int index){
        if(index==s.size()){
            if(mp.find(temp)!=mp.end()){
            temp2+=temp;
            ans.push_back(temp2);
            }
            return;
        }
        // exclude
        solve(mp,s,ans,temp+s[index],temp2,index+1);
        
        if(mp.find(temp)!=mp.end()){
            temp2+=temp;
            temp2+=" ";
            temp="";
            solve(mp,s,ans,temp,temp2,index);
        }
    }
    
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[dict[i]]++;
        }
        vector<string> ans;
        string temp="";
        string temp2="";
        solve(mp,s,ans,temp,temp2,0);
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends