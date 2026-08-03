class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26 , 0);
        for(auto &it : s) freq[it-'a']++;
        sort(freq.begin() , freq.end());
        int count = 0;
        for(int i = 25 ; i>=1 ; i--){
            if(freq[i] == 0) continue;
            int idx = i-1;
            while(idx >= 0 && freq[idx] == freq[i]){
                freq[idx]--;
                idx--;
                count++;
            }
        }
        return count;
    }
};