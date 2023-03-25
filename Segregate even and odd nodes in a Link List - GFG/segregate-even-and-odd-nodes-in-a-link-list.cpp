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
    Node* divide(int N, Node *head){
        // code here
        vector<int> v;
        
        Node* temp = head;
        int n =0;
        while(temp != NULL)
        {
            if(temp->data%2 == 0)
                v.push_back(temp->data);
                
            temp = temp->next;
            n++;
        }
        
        temp = head;
        while(temp != NULL)
        {
            if(temp->data%2 != 0)
                v.push_back(temp->data);
                
            temp = temp->next;
        }
        
        temp = head;
        
        for(int i=0;i<n;i++)
        {
            temp->data = v[i];
            temp = temp->next;
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