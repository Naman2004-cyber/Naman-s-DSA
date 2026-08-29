class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        vector<int> parent(nums.size());
        for(int i = 0 ; i<nums.size() ; i++) parent[i] = sorted[i];
        for(int i = 0 ; i<nums.size()-1 ; i++){
            if(sorted[i+1]-sorted[i] <= limit) parent[i+1] = parent[i];
        }
        unordered_map<int , int> parentFind;
        unordered_map<int , vector<int>> mpp;
        for(int i = 0 ; i<nums.size() ; i++){
            mpp[parent[i]].push_back(sorted[i]);
            parentFind[sorted[i]] = parent[i];
        }
        unordered_map<int , int> ptr;
        for(int i = 0 ; i<nums.size() ; i++){
            int component = parentFind[nums[i]];
            int x = mpp[component][ptr[component]];
            nums[i] = x;
            ptr[component]++;
        }
        return nums;
    }
};