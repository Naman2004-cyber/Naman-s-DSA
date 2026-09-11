class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<answers.size() ; i++) mpp[answers[i]]++;
        int ans = 0;
        for(auto &it : mpp){
            int type = it.first+1 , num = it.second;
            ans+=((num/type) * type);
            if(num%type != 0) ans+=type;
        }
        return ans;
    }
};