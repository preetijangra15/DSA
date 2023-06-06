//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, vector<int> adj[])
    {
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto x: adj[node])
        {
            if(!visited[x])
            {
                bool cycleDetected = dfs(x, visited, dfsVisited, adj);
                
                if(cycleDetected)
                    return true;
            }
            
            else if(dfsVisited[x])
                return true;
        }
        
        dfsVisited[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                bool checkCycle = dfs(i, visited, dfsVisited, adj);
                
                if(checkCycle)
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends