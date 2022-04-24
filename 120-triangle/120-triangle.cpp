class Solution {
public:
    
    int solver(vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>>& memo){
        if(i==n-1) return triangle[n-1][j];
        
        if(memo[i][j] != -1) return memo[i][j];
        int down = triangle[i][j] + solver(triangle, n, i+1, j, memo);
        int diag = triangle[i][j] + solver(triangle, n, i+1, j+1, memo);
        
        return memo[i][j] = min(down, diag);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solver(triangle, n, 0, 0, memo);
    }
};