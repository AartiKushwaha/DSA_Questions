class Solution {
public:
    
    void solver(vector<vector<string>> &ans, vector<int> &lr, vector<int> &ud, vector<int> &ld, int col, int n, vector<string> &board){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(lr[row]==0 and ud[n-1 + col - row]==0 and ld[row+col]==0){
                board[row][col] = 'Q';
                lr[row] = 1;
                ud[n-1+col-row] = 1;
                ld[row+col] = 1;
                solver(ans, lr, ud, ld, col+1, n, board);
                board[row][col] = '.';
                lr[row] = 0;
                ud[n-1+col-row] = 0;
                ld[row+col] = 0;
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> leftRow(n, 0), uDiag(2*n-1, 0), lDiag(2*n-1, 0);
        vector<string> board(n);
        string st(n, '.');
        for(int i=0; i<n; i++) board[i] = st;
        solver(ans, leftRow, uDiag, lDiag, 0, n, board);
        return ans;
    }
};