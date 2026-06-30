class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3 , 0);
        int distinct = 0;
        int l = 0;
        int r = 0;
        int count = 0;
        while(r < s.size())
        {
            freq[s[r]-'a']++;
            if(freq[s[r]-'a'] == 1) distinct++;
            if(distinct == 3)
            {
                while(distinct == 3)
                {
                    count+=(s.size()-r);
                    if(freq[s[l]-'a'] == 1) distinct--;
                    freq[s[l]-'a']--;
                    l++;
                }
            }
            r++;
        }
        return count;
    }
};