class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        stack<int> st;
        int n = grid.size(), m = grid[0].size();
        while(k--){
            for(int i=m-2; i>=0; i--){
                st.push(grid[n-1][i]);
            }
            for(int i=n-2; i>=0; i--){
                for(int j=m-1; j>=0; j--){
                    st.push(grid[i][j]);
                }
            }
            st.push(grid[n-1][m-1]);
    
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    grid[i][j] = st.top();
                    st.pop();
                }
            }
            
        }
        
        return grid;
    }
};