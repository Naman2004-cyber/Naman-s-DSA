class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26 , 0);
        vector<int> freq2(26 , 0);
        for(int i = 0 ; i<word1.size() ; i++) freq1[word1[i]-'a']++;
        for(int i = 0 ; i<word2.size() ; i++) freq2[word2[i]-'a']++;
        vector<int> sorted1;
        vector<int> sorted2;
        for(int i = 0 ; i<26 ; i++){
            if((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) return false;
            if(freq1[i] != 0) sorted1.push_back(freq1[i]);
            if(freq2[i] != 0) sorted2.push_back(freq2[i]);
        }
        sort(sorted1.begin() , sorted1.end());
        sort(sorted2.begin() , sorted2.end());
        if(sorted1 == sorted2) return true;
        return false;
    }
};