class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<answers.size() ; i++) mpp[answers[i]]++;
        int ans = 0;
        for(auto &it : mpp){
            if(it.first >= it.second){
                ans+=(it.first+1);
            }
            else{
                ans+=((it.second/(it.first+1))*(it.first+1));
                if(it.second%(it.first+1) != 0) ans+=(it.first+1);
            }
        }
        return ans;
    }
};