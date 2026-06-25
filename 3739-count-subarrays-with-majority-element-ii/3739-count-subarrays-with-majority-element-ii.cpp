class Solution {
public:
    void merge(vector<int> &prefix , int l , int mid , int r , long long &count)
    {
        int first = l;
        int second = mid+1;
        vector<int> temp;
        while(first <= mid && second <= r )
        {
            if(prefix[first] < prefix[second])
            {
                count+=(r-second+1);
                temp.push_back(prefix[first]);
                first++;
            }
            else 
            {
                temp.push_back(prefix[second]);
                second++;
            }
        }
        while(first <= mid)
        {
            temp.push_back(prefix[first]);
            first++;
        }
        while(second <= r)
        {
            temp.push_back(prefix[second]);
            second++;
        }
        for(int i = l ; i<=r ; i++)
        {
            prefix[i] = temp[i-l];
        }
    }
    void sortu(vector<int> &prefix , int l , int r , long long &count)
    {
        if(l >= r) return;
        int mid = (l+r)/2;
        sortu(prefix , l , mid , count);
        sortu(prefix , mid+1 , r , count);
        merge(prefix , l , mid , r , count);
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> transformed(nums.size());
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i] == target) transformed[i] = 1;
            else transformed[i] = -1;
        }
        vector<int> prefix;
        prefix.push_back(0);
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            sum+=transformed[i];
            prefix.push_back(sum);
        }
        long long count = 0;
        sortu(prefix , 0 , prefix.size()-1 , count);
        return count;
    }
};