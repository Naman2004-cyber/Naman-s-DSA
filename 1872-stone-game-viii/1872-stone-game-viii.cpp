class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int prefix = 0;
        for(int i = 0 ; i<stones.size() ; i++) prefix+=stones[i];
        int curr = prefix;
        for(int i = stones.size()-2 ; i>=1 ; i--){
            prefix-=stones[i+1];
            int take = prefix - curr;
            int skip = curr;
            curr = max(take , skip);
        }
        return curr;
    }
};