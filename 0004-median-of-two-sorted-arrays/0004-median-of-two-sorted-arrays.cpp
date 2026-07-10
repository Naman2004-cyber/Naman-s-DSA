class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = 0;

        while(left<m  && right<n)
        {
            if(nums1[left] <= nums2[right])
            {
                temp.push_back(nums1[left]);
                left++;
            }
            else
            {
                temp.push_back(nums2[right]);
                right++;
            }
        }
        while(left < m)
        {
            temp.push_back(nums1[left]);
            left++;
        }
        while(right < n)
        {
            temp.push_back(nums2[right]);
            right++;
        }

        if(temp.size()%2 == 1)
        {
            return temp[temp.size()/2];
        }
        else
        {
            return (temp[temp.size()/2] + temp[(temp.size()/2)-1])/2.0;
        }
    }
};