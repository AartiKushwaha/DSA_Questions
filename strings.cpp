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
