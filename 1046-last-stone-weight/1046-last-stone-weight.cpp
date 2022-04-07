class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int diff;
        if(stones.size()==1) return stones[0];
        while(stones.size()>1){
            sort(stones.begin(), stones.end(), greater<int>());
            int first = stones[0];
            int sec = stones[1];
            diff = first - sec;
            stones.erase(stones.begin(), stones.begin()+2);
            stones.push_back(diff);
        }
        return diff;
    }
};