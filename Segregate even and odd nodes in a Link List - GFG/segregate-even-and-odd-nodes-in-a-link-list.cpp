//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int n, Node *head){
        // code here
        
        vector<int> even;
        vector<int> odd;
        Node* temp = head;
        
        for(int i = 0;i < n;i++){
            int x = temp -> data;
            
            if(x%2 == 0)
                even.push_back(x);
                
            else
                odd.push_back(x);
                
            temp = temp -> next;
        }
        
        int e = even.size();
        int o = odd.size();
        int i = 0;
        temp = head;
        
        while(e){
            temp -> data = even[i];
            i++;
            e--;
            temp = temp -> next;
        }
        i = 0;
        while(o){
            temp -> data = odd[i];
            i++;
            o--;
            temp = temp -> next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends