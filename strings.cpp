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


//Roman to int

int n = s.size();
int ans = 0, i = n-1;
while(i>=0){
if(s[i]=='V' or s[i]=='X'){
    if(i>0 and s[i-1]=='I'){
        if(s[i]=='V'){
            ans+=4;
        }else{
            ans+=9;
        }
        i-=2;
    }else{
        if(s[i]=='V'){
            ans+=5;
        }else{
            ans+=10;
        }
        i-=1;
    }
}
else if(s[i]=='L' or s[i]=='C'){
    if(i>0 and s[i-1]=='X'){
        if(s[i]=='L'){
            ans+=40;
        }else{
            ans+=90;
        }
        i-=2;
    }else{
        if(s[i]=='L'){
            ans+=50;
        }else{
            ans+=100;
        }
        i-=1;
    }
}
else if(s[i]=='D' or s[i]=='M'){
    if(i>0 and s[i-1]=='C'){
        if(s[i]=='D'){
            ans+=400;
        }else{
            ans+=900;
        }
        i-=2;
    }else{
        if(s[i]=='D'){
            ans+=500;
        }else{
            ans+=1000;
        }
        i-=1;
    }
}else{
    ans+=1;
    i--;
}
}
return ans;
