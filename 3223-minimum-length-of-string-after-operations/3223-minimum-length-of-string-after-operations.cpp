class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char , int> mpp;
        for(int i = 0 ; i<s.size() ; i++) mpp[s[i]]++;
        int count = 0;
        int total = s.size();
        for(auto &it : mpp){
            if(it.second%2 == 0){
                total-=(it.second-2);
            }
            else{
                total-=(it.second-1);
            }
        }
        return total;
    }
};