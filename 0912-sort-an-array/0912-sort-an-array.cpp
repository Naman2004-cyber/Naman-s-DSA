class Solution {
public:
    void merge(vector<int>& nums , int l , int mid , int r)
    {
        int first = l;
        int second = mid+1;
        vector<int> temp;
        while(first <= mid && second <= r)
        {
            if(nums[first] <= nums[second])
            {
                temp.push_back(nums[first]);
                first++;
            }
            else
            {
                temp.push_back(nums[second]);
                second++;
            }
        }
        while(first <= mid)
        {
            temp.push_back(nums[first]);
            first++;
        }
        while(second <= r)
        {
            temp.push_back(nums[second]);
            second++;
        }
        for(int i = l ; i<=r ; i++)
        {
            nums[i] = temp[i-l];
        }
    }
    void sortu(vector<int>& nums , int l , int r)
    {
        if(l >= r) return;
        int mid = (r+l)/2;
        sortu(nums , l , mid);
        sortu(nums , mid+1 , r);
        merge(nums , l , mid , r);
    }
    vector<int> sortArray(vector<int>& nums) {
        sortu(nums , 0 , nums.size()-1);
        return nums;
    }
};