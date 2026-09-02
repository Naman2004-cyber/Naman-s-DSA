class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> finalAns;
        for(int i = 0 ; i<nums.size() ; i++){
            int num = nums[i];
            string ans = "";
            while(num > 0){
                int index = 31 - __builtin_clz(num);
                num-=(1 << index);
                if(index == 26) ans+="zz";
                else ans+=(char('a' + index));
            }
            finalAns.push_back(ans);
        }
        return finalAns;
    }
};