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
    
    int first=0, second=0;
     for(int i=0; i<s.length(); i++)
     {
         if(i%2==0)
         {
             if(s[i]!='0')
             first++;
         }
         else
         {
             if(s[i]!='1')
             first++;
         }
         
         if(i%2==0)
         {
             if(s[i]!='1')
             second++;
         }
         else
         {
             if(s[i]!='0')
             second++;
         }
         
     }
     
     //cout<<first<<" "<<second<<endl;
     return min(first,second);
}