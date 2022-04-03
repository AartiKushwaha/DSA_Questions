class Solution {
public:
    
    
    void solver(string s, vector<string> &ans, string temp, vector<string>& codes){
        if(s.size()==0){
            ans.push_back(temp);
            return;
        }
        char c = s[0];
        string code = codes[c-'0'];
        string ros = s.substr(1);
        for(int i=0; i<code.size(); i++){
            solver(ros, ans, temp+code[i], codes);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> codes = {".", "..", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
        vector<string> ans;
        solver(digits, ans, "", codes);
        return ans;
    }
};