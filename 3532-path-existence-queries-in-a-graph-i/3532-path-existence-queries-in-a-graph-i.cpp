class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int compo = 0;
        vector<int> mpp(n);
        mpp[0] = compo;
        for(int i = 1 ; i<nums.size(); i++)
        {
            if(nums[i]-nums[i-1] <= maxDiff){
                mpp[i] = compo;
            }
            else
            {
                compo++;
                mpp[i] = compo;
            }
        }
        vector<bool> ans;
        for(int i = 0 ; i<queries.size() ; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(mpp[u] == mpp[v]){
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};