//Reverse words in a string 
//https://leetcode.com/problems/reverse-words-in-a-string/submissions/

string reverseWords(string s) {
      stringstream ss(s);
      string result, word;

      while (ss >> word)
          if (word != "")
              result = word + " " + result;

      if (result != "")
          result.pop_back();

      return result;
  }

//https://leetcode.com/problems/longest-palindrome/
int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int ans = 0, flag1 = 0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if((it->second) % 2 == 0) ans+=it->second;
            else if(it->second == 1) flag1 = 1;
            else if(it->second % 2 == 1){
                ans+=(it->second)-1;
                flag1=1;
            } 
        }
        if(flag1==1) ans+=1;
        return ans;
      }
