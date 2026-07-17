class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char , int> mpp;
        for(int i = 0 ; i<s.size() ; i++) mpp[s[i]]++;
        int count = 0;
        int total = s.size();
        for(auto &it : mpp){
            int val = it.second;
            while(val >= 3){
                int a = val/3;
                total-=(a*2);
                val = val - (a*2);
            }
        }
        return total;
    }
};