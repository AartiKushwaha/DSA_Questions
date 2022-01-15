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

Q) Detect Cycle in undirected graph

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool checkCycle(int curr, vector<int> &vis, vector<int> adj[]){
        
        vis[curr] = 1;
        queue<pair<int,int>> q;
        q.push({curr,-1});
        while(!q.empty()){
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for(auto adjEle: adj[node]){
                if(!vis[adjEle]){
                    vis[adjEle] = 1;
                    q.push({adjEle, node});
                }else if(adjEle != prev) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,vis,adj)) return true;
            }
        }
        return false;
    }
};


//isBipartite

//Using BFS


class Solution {
public:

    bool check(int node, vector<int>adj[], int vis[]){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it: adj[curr]){
                if(vis[it] == -1){
                    vis[it] = 1 - vis[curr];
                    q.push(it);
                }else if(vis[it] == vis[curr]) return false;
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
        int vis[V];
        memset(vis, -1, sizeof vis);
        for(int i=0; i<V; i++){
            if(vis[i] == -1){
                if(!check(i, adj, vis)) return false;
            }
        }
        return true;
	}

};
