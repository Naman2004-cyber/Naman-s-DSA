class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> primes(101 , true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 2 ; i*i<=100 ; i++){
            if(primes[i]){
                for(int j = i*i ; j<=100 ; j+=i){
                    primes[j] = false;
                }
            }
        }
        int first = -1;
        int last = -1;
        for(int i = 0 ;i< nums.size() ; i++) {
            if(primes[nums[i]]) {
                first = i;
                break;
            }
        }
        for(int i = nums.size()-1 ;i>=0; i--) {
            if(primes[nums[i]]) {
                last = i;
                break;
            }
        }
        return last - first;
    }
};