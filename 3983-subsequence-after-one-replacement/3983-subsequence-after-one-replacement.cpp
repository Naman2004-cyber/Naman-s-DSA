class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int done = 0;
        unordered_map<char , int> mpp;
        unordered_map<char , int> mpp1;
        for(auto &it : t) mpp[it]++;
        for(auto &it : s) mpp1[it]++;
        unordered_map<char , int> lastseent;
        unordered_map<char , int> lastseens;
        for(int i = 0 ; i<t.size() ; i++) lastseent[t[i]] = i;
         for(int i = 0 ; i<s.size() ; i++) lastseens[s[i]] = i;
        while(i < s.size() && j < t.size())
        {
            if(s[i] == t[j])
            {
                mpp1[s[i]]--;
                if(mpp1[s[i]] == 0) mpp1.erase(s[i]);
                i++;
            }
            else if(done == 0 && (((mpp[s[i]] < mpp1[s[i]]) && (i == lastseens[s[i]] || lastseent[s[i]] == t.size()-1)) || ( (mpp[s[i]] ==  mpp1[s[i]]) && lastseent[s[i]] == t.size()-1)))
            {
                done = 1;
                mpp1[s[i]]--;
                if(mpp1[s[i]] == 0) mpp1.erase(s[i]);
                i++;
            }
            mpp[t[j]]--;
            if(mpp[t[j]] == 0) mpp.erase(t[j]);
            j++;
        }
        if(i == s.size()) return true;
        return false;
    }
};