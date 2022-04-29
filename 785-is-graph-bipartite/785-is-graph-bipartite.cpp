class Solution {
public:
    
    bool check(int node, vector<vector<int>>& graph, int vis[]){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it: graph[curr]){
                if(vis[it] == -1){
                    vis[it] = 1 - vis[curr];
                    q.push(it);
                }else if(vis[it] == vis[curr]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis[n];
        memset(vis, -1, sizeof vis);
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                if(!check(i, graph, vis)) return false;
            }
        }
        return true;
    }
};