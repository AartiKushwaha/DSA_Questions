//BFS    ----> Connected components, nodes starting with zero

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
