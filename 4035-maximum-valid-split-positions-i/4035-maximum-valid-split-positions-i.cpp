class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        if(nums.size() == 2){
            if(nums[0] == nums[1]) return 1;
            return 0;
        }
        vector<int> prefixGcd;
        vector<int> suffixGcd;
        int maxi = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            // do not consider nums[i]
            int gcdpre = 0;
            for(int j = 0 ; j<nums.size() ; j++){
                if(j == i) continue;
                gcdpre = __gcd(nums[j] , gcdpre);
                prefixGcd.push_back(gcdpre);
            }
            int gcdSuf = 0;
            for(int j = nums.size()-1 ; j>=0 ; j--){
                if(j == i) continue;
                gcdSuf = __gcd(nums[j] , gcdSuf);
                suffixGcd.push_back(gcdSuf);
            }
            reverse(suffixGcd.begin() , suffixGcd.end());
            int count = 0;
            for(int j = 0 ; j<prefixGcd.size()-1 ; j++){
                if(prefixGcd[j] == suffixGcd[j+1]) count++;
            }
            maxi = max(maxi , count);
            prefixGcd.clear();
            suffixGcd.clear();
        }
        // for(int i = 0 ; i<prefixGcd.size() ; i++) cout << prefixGcd[i] << " ";
        vector<int> prefAll;
        vector<int> suffAll;
        int gcdPreAll = 0;
        int gcdSufAll = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            gcdPreAll = __gcd(gcdPreAll , nums[i]);
            prefAll.push_back(gcdPreAll);
        }
        for(int i = nums.size()-1 ; i>=0 ; i--){
            gcdSufAll = __gcd(gcdSufAll , nums[i]);
            suffAll.push_back(gcdSufAll);
        }
        reverse(suffAll.begin() , suffAll.end());
        int countAll = 0;
        for(int i = 0 ; i<nums.size()-1 ; i++){
            if(prefAll[i] == suffAll[i+1]) countAll++;
        }
        maxi = max(maxi , countAll);
        return maxi;
    }
};