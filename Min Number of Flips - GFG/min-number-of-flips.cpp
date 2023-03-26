//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    
    int n = s.size();
    
    string str = "";
    
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
            str.push_back('1');
            
        else
            str.push_back('0');
    }
    
    string str1 = "";
    
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
            str1.push_back('0');
            
        else
            str1.push_back('1');
    }
    
    int cnt = 0, c = 0;
    
    for(int i=0;i<n;i++)
    {
        if(s[i] != str[i])
            cnt++;
    }
    
    for(int i=0;i < n;i++)
    {
        if(s[i] != str1[i])
            c++;
    }
    
    return min(cnt, c);
    
}