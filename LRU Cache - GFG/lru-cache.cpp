//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    
    Node(int _key, int _val){
        val = _val;
        key = _key;
    }
};


class LRUCache
{


    public:
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    int cap;
    unordered_map<int, Node*>mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newnode){
        Node* temp = head->next;
        
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deleteNode(Node* delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        
        delprev ->next = delnext;
        delnext->prev = delprev;
    }

    int GET(int key_)
    {
        // your code here
        
        if(mp.find(key_) != mp.end()){
            Node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            mp[key_] = head->next;
            return res;
        }
        
        return -1;
        
    }
    
    //Function for storing key-value pair.
    void SET(int key_, int value)
    {
        // your code here   
        if(mp.find(key_) != mp.end()) {
            Node* existingnode = mp[key_];
            mp.erase(key_);
            deleteNode(existingnode);
        }

        if(mp.size() == cap){
            mp.erase(tail ->prev ->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key_, value));
        mp[key_] = head ->next;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends