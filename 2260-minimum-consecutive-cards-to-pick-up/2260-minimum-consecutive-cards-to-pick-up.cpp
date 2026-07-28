class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int , int> mpp;
        int mini = INT_MAX;
        for(int i = 0 ; i<cards.size() ; i++){
            if(mpp.find(cards[i]) != mpp.end()){
                int dist = i - mpp[cards[i]] + 1;
                mini = min(mini , dist);
            }
            mpp[cards[i]] = i;
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};