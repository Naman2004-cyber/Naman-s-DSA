class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // vector<int> dp(stoneValue.size()+1);
        int plus1 = 0 , plus2 = 0 , plus3 = 0;
        for(int i = n-1 ; i>=0 ; i--){
            int one = stoneValue[i] - plus1;
            int two = -2001;
            if(i+1 < stoneValue.size()){
                two = stoneValue[i] + stoneValue[i+1] - plus2;
            }
            int three = -2001;
            if(i+2 < stoneValue.size()){
                three = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - plus3;
            }
            int curr = max(one , max(two , three));
            plus3 = plus2;
            plus2 = plus1;
            plus1 = curr;
        }
        int bestDiff = plus1;
        if(bestDiff > 0) return "Alice";
        if(bestDiff < 0) return "Bob";
        return "Tie";
    }
};