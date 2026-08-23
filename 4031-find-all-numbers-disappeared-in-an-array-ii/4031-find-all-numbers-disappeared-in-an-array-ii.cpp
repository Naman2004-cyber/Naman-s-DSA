class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> freq(1e5+1 , 0);
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]]++;
        vector<vector<int>> ans;
        int start = -1;
        int end = -1;
        for(int i = lower ; i<=upper ; i++){
            if(freq[i] == 0){
                if(start == -1) {
                    start = i;
                    end = i;
                }
                else{
                    end = i;
                }
            }
            else{
                if(start != -1 && end != -1) ans.push_back({start , end});
                start = -1;
                end = -1;
            }
        }
        if(start != -1 && end != -1) ans.push_back({start , end});
        return ans;
    }
};