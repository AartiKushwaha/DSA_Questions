class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nr = matrix.size();
        int nc = matrix[0].size();
        int cr = 0, cc = nc-1;
        while(cc >= 0 and cr < nr){
            if(matrix[cr][cc] == target) return true;
            else if(matrix[cr][cc] < target){
                cr++;
            }else{
                cc--;
            }
        }
        return false;
    }
};