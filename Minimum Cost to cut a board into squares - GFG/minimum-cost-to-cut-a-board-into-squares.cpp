//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    // static bool cmp(pair<int, int> p1, pair<int, int> p2)
    // {
    //     if(p1.)
    // }
    
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        
        
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int answer = 0;
        int i = 0;
        int j = 0;
        int hzc=1;
        int vc = 1;
        while(i<M-1 && j< N-1){
            if(X[i]>Y[j]){
                answer += X[i]*vc;
                i++;
                hzc++;
            }
            else{
                answer+= Y[j]*hzc;
                vc++;
                j++;
            }
        }
        while(i<M-1){
            answer+=X[i]*vc;
            i++;
            hzc++;
            
        }
         while(j<N-1){
            answer+=Y[j]*hzc;
            j++;
            vc++;
            
        }
        return answer;
        
        
        // sort(X.begin(), X.end(), greater<int>());
        // sort(Y.begin(), Y.end(), greater<int>());
        
        // int i = 0, j = 0, hzc = 1, vc = 1;
        // int ans = 0;
        
        // while(i < M-1 && j < N-1){
        //     if(X[i] > Y[j]){
        //         ans += X[i]*vc;
        //         i++;
        //         hzc++;
        //     }
        //     else{
        //         ans += Y[j]*hzc;
        //         vc++;
        //         j++;
                
        //     }
        // }
        
        // while(i < M-1){
        //     ans += X[i]*vc;
        //     i++;
        //     hzc++;
        // }
        // while(j < N-1){
        //     ans += Y[i]*hzc;
        //     j++;
        //     vc++;
        // }
        
        // return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends