//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> lps(int n, string s) {
          int i=1,j=0;
          vector<int>ans(n,0);
          while(i<n) {
              if(s[i]==s[j]) {
                 ans[i]=j+1;
                 i++;
                 j++;
              }
              else {
                  if(j!=0) {
                      j=ans[j-1];
                  }
                  else {
                      i++;
                  }
              }
          }
          return ans;
      }

int minChar(string str){
       
        int n = str.length();
        string s = str;
        reverse(str.begin(),str.end());
        string new_s = s + '$' + str;
        vector<int> lps_ans = lps((2*n+1),new_s);
        return n-lps_ans.back();
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends