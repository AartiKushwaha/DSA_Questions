class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, h = s.size()-1, cnt = 0;
        while(l<h){
            if(s[l]==s[h]){
                l++; h--;
            }else{
                cnt++;
                l++;
            }
            if(cnt>1) break;
        }
        l = 0;
        h = s.size()-1;
        int cnt1 = 0;
        while(l<h){
            if(s[l]==s[h]){
                l++; h--;
            }else{
                cnt1++;
                h--;
            }
            if(cnt1>1) break;
        }
        if(cnt==1 or cnt1==1) return true;
        if(cnt==0 or cnt1==0) return true;
        return false;
    }
};