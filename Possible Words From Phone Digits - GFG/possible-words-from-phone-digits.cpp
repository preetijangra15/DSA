//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int i, int n, vector<string>& nums, string str, vector<string>& ans)
    {
        if(i == n)
        {
            ans.push_back(str);
            return;
        }
        
        string temp = nums[a[i]];
        
        for(int j = 0; j < temp.size(); j++)
        {
            str.push_back(temp[j]);
            solve(a, i+1, n, nums, str, ans);
            str.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        
        vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string str = "";
        solve(a, 0, n, nums, str, ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends