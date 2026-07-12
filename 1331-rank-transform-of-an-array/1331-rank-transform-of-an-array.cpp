class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int , int> mpp;
        vector<int> use = arr;
        sort(use.begin() , use.end());
        int rank = 1;
        for(int i = 0 ; i<use.size() ; i++){
            if(i == 0){
                mpp[use[i]] = rank;
            }
            else
            {
                if(use[i] > use[i-1]){
                    rank++;
                    mpp[use[i]] = rank;
                }
                else{
                    mpp[use[i]] = rank;
                }
            }
        }
        // for(auto &it : mpp){
        //     cout << it.first << " ----> " << it.second << endl;
        // }
        vector<int> ans(arr.size());
        for(int i = 0 ; i<use.size() ; i++){
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};