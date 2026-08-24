class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int> prefix(stones.size() , 0);
        int  sum = 0;
        for(int i = 0 ; i<stones.size() ; i++){
            sum+=stones[i];
            prefix[i] = sum;
        }
        int curr = prefix[stones.size()-1];
        for(int i = stones.size()-2 ; i>=1 ; i--){
            int take = prefix[i] - curr;
            int skip = curr;
            curr = max(take , skip);
        }
        return curr;
    }
};