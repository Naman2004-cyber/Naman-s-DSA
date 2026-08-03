class Solution {
public:
    int doit(int startIdx , int endIdx , vector<int>& nums){
        if(startIdx > endIdx) return 0;
        int startSe = nums[startIdx] + min(doit(startIdx+2 , endIdx , nums) , doit(startIdx+1 , endIdx-1 , nums));
        int endSe = nums[endIdx] + min(doit(startIdx , endIdx-2 , nums) , doit(startIdx+1 , endIdx-1 , nums));
        return max(startSe , endSe);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin() , nums.end() , 0);
        int player1Sum = doit(0 , nums.size()-1 , nums);
        cout << player1Sum;
        if(player1Sum >= (total - player1Sum)) return true;
        return false;
    }
};