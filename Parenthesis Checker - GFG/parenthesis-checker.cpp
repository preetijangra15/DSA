//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string str)
    {
        // stack<char>s;
        // for(char x:str){
        //     if(x=='(' || x=='{' || x=='['){
        //         s.push(x);
        //     }
        //     else{
        //         if(s.empty()){
        //             return false;
        //         }
        //         else if(x==')' && s.top()!='('){
        //             return false;
        //         }
        //          else if(x=='}' && s.top()!='{'){
        //             return false;
        //         }
        //         else if(x==']' && s.top()!='['){
        //             return false;
        //         }
        //         else{
        //             s.pop();
        //         }
        //     }
        // }
        // return s.empty();
        
        stack<char> st;
        for(auto x:str){
            if(x == '(' || x == '{' || x == '[')
                st.push(x);
                
            else{
                if(st.empty())
                    return false;
                    
                else if(x == ')' && st.top() != '(')
                    return false;
                    
                else if(x == '}' && st.top() != '{')
                    return false;
                    
                else if(x == ']' && st.top() != '[')
                    return false;
                    
                else
                    st.pop();
            }
        }
        
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends