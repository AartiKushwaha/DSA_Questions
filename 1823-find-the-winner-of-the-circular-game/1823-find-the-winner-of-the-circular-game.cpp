class Solution {
public:
    
    void winner(vector<int> friends, int k, int idx, int &ans){
        if(friends.size()==1){
            ans = friends[0];
            return;
        }
        idx = (idx+k)%(friends.size());
        friends.erase(friends.begin()+idx);
        winner(friends, k, idx, ans);
    }
    
    int findTheWinner(int n, int k) {
        vector<int> vec;
        int ans;
        for(int i=1; i<=n; i++) vec.push_back(i);
        winner(vec, k-1, 0, ans);
        return ans;
    }
};