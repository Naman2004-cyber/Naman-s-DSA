// so in this question we have to divide the elements of the arrays into subarrays of size k in which elements are in increasing consecutive order , this directly gives us an indication that we want the elements in increasing order , now one number can come multiple times and can be used in different subarrays this indicates that we must know the frequency of the elements , after that we just need to know what can be the first element of the subarray because all number can be derived from it like if the first element is 2 , next will be 3 then 4 and so on ,,, we must want that the smallest exhausted number should start the new subarray ,, because if we dont do that and we start with a bigger number available then there are changes that the next greater consicutive numbers cannot be found ,,, so always start from the smallest available numbers ,,, so just sort the given array and start from it ,,, once we arrive at a number check if it is available , if yes then check other consecutive k-1 elements are available or not from the map if no return false , as we were not able to use the first element of the subarray ,,, but if yes we found , then decrease their frequency by 1 ,,, then keep on gooing through the array and see the non exhausted number and see if subarray can be formed from them

// always starting the subarray from the smallest unused number gives us an assurence that all number smaller than it are already used , so the number subarrays can start from it only 

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0) return false;
        sort(nums.begin() , nums.end());
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<nums.size() ; i++) mpp[nums[i]]++;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(mpp[nums[i]] == 0) continue;
            for(int j = 0 ; j<k ; j++)
            {
                if(mpp[nums[i]+j] == 0) return false;
                mpp[nums[i]+j]--;
            }
        }
        return true;
    }
};