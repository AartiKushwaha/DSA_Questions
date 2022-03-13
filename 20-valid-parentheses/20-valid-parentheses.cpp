class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='(' or ch=='{' or ch=='[') st.push(ch);
            else{
                char match;
                switch(ch){
                    case ')':
                        match = '(';
                        break;
                    case '}':
                        match = '{';
                        break;
                    case ']':
                        match = '[';
                        break;
                }
                if(!st.empty()){
                    if(match!=st.top()) return false;
                    else st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};