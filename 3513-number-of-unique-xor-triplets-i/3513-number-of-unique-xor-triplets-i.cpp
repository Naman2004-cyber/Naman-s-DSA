class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int number = nums.size();
        if(number <= 2) return number;
        vector<int> store;
        int index = 0;
        int val = 1;
        for(int i = 0 ; i<=16 ; i++){
            val = val*2;
            if(number < val) break;
            index++;
        }
        cout << index;
        int ans = pow(2 , index+1);
        return ans;
    }
};