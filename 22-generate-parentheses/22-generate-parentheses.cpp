class Solution {
public:
    
    void solver(vector<string> &ans, string temp, int op, int cl, int n){
        if(op==n and cl==n){
            ans.push_back(temp);
            return;
        }
        if(op<n) solver(ans, temp+'(', op+1, cl, n);
        if(cl<n and cl<op) solver(ans, temp+')', op, cl+1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solver(ans, "", 0, 0, n);
        return ans;
    }
};