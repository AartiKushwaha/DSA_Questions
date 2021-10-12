//BFS    ---->for disconnected components, nodes starting with zero

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsRes;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfsRes.push_back(node);
                    for(auto adjEle: adj[node]){
                        if(!visited[adjEle]){
                            q.push(adjEle);
                            visited[adjEle] = 1;
                        }
                    }
                }
            }
        }
        return bfsRes;
    }
};


//DFS   ---->for Connected components

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans){
        ans.push_back(node);
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, vis, adj, ans);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfsRes;
        vector<int> vis(V,0);
        dfs(0,vis,adj,dfsRes);
        return dfsRes;
    }
};
