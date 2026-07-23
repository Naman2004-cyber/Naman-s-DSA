class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int number = nums.size();
        if(number <= 2) return number;
        int index = 0;
        int val = 1;
        for(int i = 0 ; i<=16 ; i++){
            val = val*2;
            if(number < val) break;
            index++;
        }
        cout << index;
        int ans = 1 << (index+1);
        return ans;
    }
};