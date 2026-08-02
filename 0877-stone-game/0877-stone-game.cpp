class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = 0;
        int firstHalf = 0;
        int oneSkip = 0;
        for(int i = 0 ; i<n ; i++){
            if(i < (n/2)) firstHalf+=piles[i];
            if(i%2 == 0) oneSkip+=piles[i];
            total+=piles[i];
        }
        int bobsecondHalf = total - firstHalf;
        if(firstHalf != bobsecondHalf) return true;
        int leftSkip = total - oneSkip;
        if(oneSkip != leftSkip) return true;
        return false;
    }
};