class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        int i=-1;
        for(auto st: ops){
            if(st=="C"){
                scores.pop_back();
                i--;
            }else if(st=="D"){
                scores.push_back(2*scores[i]);
                i++;
            }else if(st=="+"){
                scores.push_back(scores[i]+scores[i-1]);
                i++;
            }else{
                scores.push_back(stoi(st));
                i++;
            }
        }
        int sum=0;
        for(int num: scores) sum+=num;
        return sum;
    }
};