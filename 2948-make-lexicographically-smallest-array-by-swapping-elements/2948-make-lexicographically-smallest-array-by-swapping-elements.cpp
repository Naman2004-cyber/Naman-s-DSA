class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        vector<int> parent(nums.size());
        for(int i = 0 ; i<nums.size() ; i++){
            parent[i] = sorted[i];
        }
        for(int i = 0 ; i<nums.size()-1 ; i++){
            if(sorted[i+1]-sorted[i] <= limit){
                parent[i+1] = parent[i];
            }
        }
        // for(int i = 0 ; i<nums.size() ; i++) cout << parent[i] << " ";
        unordered_map<int , int> parentFind;
        unordered_map<int , multiset<int>> mpp;
        for(int i = 0 ; i<nums.size() ; i++){
            mpp[parent[i]].insert(sorted[i]);
            parentFind[sorted[i]] = parent[i];
        }
        for(auto &it : mpp){
            cout << it.first << " --> ";
            for(auto &a : it.second) cout << a << " ";
            cout << endl;
        }
        for(int i = 0 ; i<nums.size() ; i++){
            int component = parentFind[nums[i]];
            int x = *mpp[component].begin();
            nums[i] = x;
            mpp[component].erase(mpp[component].find(x));
        }
        return nums;
    }
};