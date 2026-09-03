class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0,odd=0;
        int leastodd = INT_MAX;
        for(int i = 0 ; i<nums1.size() ; i++)
        {
            if(nums1[i]%2 == 0) even++;
            if(nums1[i]%2 != 0)
            {
                odd++;
                if(nums1[i] < leastodd) leastodd = nums1[i];
            }
        }
        if(even == 0 || odd == 0) return true;
        for(int i = 0 ; i<nums1.size() ; i++) if(nums1[i]%2 == 0) if(leastodd > nums1[i]) return false;
        return true;
    }
};