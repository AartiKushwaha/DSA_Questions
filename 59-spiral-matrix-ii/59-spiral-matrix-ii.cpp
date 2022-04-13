class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int top=0,btm=n-1,lft=0,rgt=n-1,num=1;
        while(num<=n*n){
            for(int col=lft;col<=rgt;col++) ans[top][col]=num++;
            top++;
            for(int row=top;row<=btm;row++) ans[row][rgt]=num++;
            rgt--;
            for(int col=rgt;col>=lft;col--) ans[btm][col]=num++;
            btm--;
            for(int row=btm;row>=top;row--) ans[row][lft]=num++;
            lft++;
        }
        return ans;
    }
};