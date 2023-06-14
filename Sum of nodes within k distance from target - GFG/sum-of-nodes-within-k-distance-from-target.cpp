//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    int sum_at_distK(Node* root, int target, int k)
    {
        // code here
        unordered_map<Node*, Node*> parents;
        
        queue<Node*> q;
        q.push(root);
        Node* tar;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == target)
                tar = temp;
                
            if(temp->left){
                parents[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parents[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        unordered_map<Node*, bool> visited;
        visited[tar] = true;
        q.push(tar);
        int ans = 0;
        int count = 0;
        while(!q.empty()){
            
            int n = q.size();
            
            if(count++ == k) break;
            
            for(int i = 0;i<n;i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && !visited[temp->left]) 
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                    
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                    
                if(parents[temp] && !visited[parents[temp]])
                {
                    q.push(parents[temp]);
                    visited[parents[temp]] = true;
                }
                
                ans += temp->data;
            }
            
        }
        
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            
            ans += temp->data;
        }
        //ans += tar->data;
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends