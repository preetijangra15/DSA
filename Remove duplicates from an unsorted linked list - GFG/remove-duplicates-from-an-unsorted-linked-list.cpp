//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
    //  Node* temp = head;
    //  vector<int> v;
    //  int count = 0;
    //  while(temp != NULL)
    //  {
    //      v.push_back(temp->data);
    //      count++;
    //      temp = temp->next;
    //  }
     
    //  unordered_map<int, int> mp;
     
    //  for(int i=0;i<count;i++)
    //  {
    //      mp[v[i]]++;
    //  }
    //  temp = head;

    //  for(int i=0;i<count;i++)
    //  {
    //      if(mp[v[i]] >= 1)
    //      {
    //          temp->data = v[i];
    //          mp[v[i]] = 0;
    //          temp = temp->next;
    //      }
    //  }
     
    //  cout<<temp->data<<endl;
    //  temp = NULL;
    //  return head;
    
    Node* temp = head;
    vector<int> v;
    int count = 0;
    
    while(temp != NULL)
    {
        v.push_back(temp->data);
        count++;
        temp = temp->next;
    }
    
    unordered_map<int, int>mp;
    
    for(int i=0;i<count;i++)
        mp[v[i]]++;
        
    
    temp = head;
    
    for(int i=0;i<count;i++)
    {
        if(mp[v[i]] > 0)
        {   
            //cout<<v[i]<<" "<<mp[v[i]]<<endl;
            temp->data = v[i];
            mp[v[i]] = -1;
            // if(i == count-2)
            //     temp->next = NULL;
            // else
            temp = temp->next;
        }
        
    }
    // temp->data = NULL;
    // temp->next = NULL;
    // temp = NULL;
    
    int n = mp.size();
    temp = head;
    int i = 0;
    while(i != n-1)
    {
        temp = temp->next;
        i++;
    }
        
    temp->next = NULL;
        
    return head;
     
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends