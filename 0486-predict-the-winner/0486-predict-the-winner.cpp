class Solution {
public:
    int curr[20];
    int prev[20];
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j>=0 ; j--){
                if(j == i) prev[j] = nums[i];
            }
        }
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 0 ; j<n ; j++){
                if(j < i) continue;
                int startSe = 0;
                if(i+1 < n) startSe = nums[i] - prev[j];
                int endSe = 0;
                if(j-1 >= 0) endSe = nums[j] - curr[j-1];
                curr[j] = max(startSe , endSe);
            }
            swap(curr , prev);
        }
        if(prev[n-1] >= 0) return true;
        return false;
    }
};