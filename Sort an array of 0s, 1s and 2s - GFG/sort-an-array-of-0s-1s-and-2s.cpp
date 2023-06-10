//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        
        vector<int> v;
        
        int countz = 0, counto = 0, countt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
                countz++;
                
            else if(arr[i] == 1)
                counto++;
                
            else
                countt++;
        }
        
        while(countz)
        {
            v.push_back(0);
            countz--;
        }
        
        while(counto)
        {
            v.push_back(1);
            counto--;
        }
        
        while(countt)
        {
            v.push_back(2);
            countt--;
        }
        
        
        for(int i=0;i<n;i++)
            arr[i] = v[i];
            
        //return arr;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends