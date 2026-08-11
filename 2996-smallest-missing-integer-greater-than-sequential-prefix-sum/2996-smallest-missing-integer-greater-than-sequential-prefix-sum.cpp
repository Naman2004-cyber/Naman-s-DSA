class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i] == nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int> st;
        st.insert(nums.begin() , nums.end());
        while(true){
            if(st.count(sum) == 0) return sum;
            sum++;
        }
        return 0;
    }
};