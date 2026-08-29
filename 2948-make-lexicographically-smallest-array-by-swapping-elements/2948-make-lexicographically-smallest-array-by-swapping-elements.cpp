class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        vector<int> parent = sorted;
        parent[0] = sorted[0];
        for(int i = 1 ; i<nums.size() ; i++){
            if(sorted[i]-sorted[i-1] <= limit) parent[i] = parent[i-1];
        }
        unordered_map<int , int> findParent;
        unordered_map<int , vector<int>> components;
        for(int i = 0 ; i<nums.size() ; i++){
            findParent[sorted[i]] = parent[i];
            components[parent[i]].push_back(sorted[i]);
        }
        unordered_map<int , int> ptr;
        for(int i = 0 ; i<nums.size() ; i++){
            int currComponent = findParent[nums[i]];
            int x = components[currComponent][ptr[currComponent]];
            nums[i] = x;
            ptr[currComponent]++;
        }
        return nums;
    }
};