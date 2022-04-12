class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> temp = board;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cnt = 0;
                //up
                if(i>0) cnt+=temp[i-1][j];
                //up-left
                if(i>0 and j>0) cnt+=temp[i-1][j-1];
                //up-down
                if(i>0 and j<n-1) cnt+=temp[i-1][j+1];
                //left
                if(j>0) cnt+=temp[i][j-1];
                //right
                if(j<n-1) cnt+=temp[i][j+1];
                //down
                if(i<m-1) cnt+=temp[i+1][j];
                //down-left
                if(i<m-1 and j>0) cnt+=temp[i+1][j-1];
                //down-right
                if(i<m-1 and j<n-1) cnt+=temp[i+1][j+1];
                
                if(board[i][j]==0){
                    if(cnt==3) board[i][j] = 1;
                }else{
                    if(cnt<2) board[i][j] = 0;
                    else if(cnt>3) board[i][j] = 0;
                }
            }
        }
    }
};