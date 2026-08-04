class Solution {
public:
    int numSplits(string s) {
        vector<int> freq(26 , 0);
        int distinct = 0;
        vector<int> distinctAtIdx(s.size() , 0);
        for(int i = s.size()-1 ; i>=0 ; i--) {
            if(freq[s[i]-'a'] == 0) distinct++;
            freq[s[i]-'a']++;
            distinctAtIdx[i] = distinct;
        }
        // for(int i = 0 ; i<s.size() ; i++) cout << distinctAtIdx[i] << " ";
        int ans = 0;
        int countDistinct = 0;
        vector<int> countFreq(26 , 0);
        for(int i = 0 ; i<s.size()-1 ; i++){
            if(countFreq[s[i]-'a'] == 0) countDistinct++;
            countFreq[s[i]-'a']++;
            if(countDistinct == distinctAtIdx[i+1]) ans++;
        }
        return ans;
    }
};