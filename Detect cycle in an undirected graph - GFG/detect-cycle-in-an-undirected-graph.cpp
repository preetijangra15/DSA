//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node, vector<int> adj[], unordered_map<int, bool>& visited){
        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = true;
        
        while(!q.empty()){
            int temp = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto it: adj[temp]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it, temp});
                }
                
                else if(parent != it)
                    return true;
            }
            
        }
        
        return false;
    }
    
    bool dfs(int node, int parent, vector<int> adj[], unordered_map<int, bool>& visited){
        visited[node] = true;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, node, adj, visited) ==  true) return true;
            }
            
            else if(parent != it)
                return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // unordered_map<int, bool> visited;
        
        // for(int i = 0;i<V;i++){
        //     if(!visited[i])
        //         if(bfs(i, adj, visited)) return true;
        // }
        
        // return false;
        
        unordered_map<int, bool> visited;
        
        for(int i = 0;i < V;i++){
            if(!visited[i]){
                if(dfs(i, -1, adj, visited)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends