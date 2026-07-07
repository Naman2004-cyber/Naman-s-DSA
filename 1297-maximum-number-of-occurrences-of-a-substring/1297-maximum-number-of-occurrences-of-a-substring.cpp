class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string , int> mpp;
        int l = 0;
        int r = 0;
        int unique = 0;
        vector<int> freq(26 , 0);
        while(r < s.size())
        {
            freq[s[r]-'a']++;
            if(freq[s[r]-'a'] == 1) unique++;
            while(unique > maxLetters)
            {
                if(freq[s[l]-'a'] == 1) unique--;
                freq[s[l]-'a']--;
                l++;
            }
            int size = r-l+1;
            int index = l;
            if(size > maxSize)
            {
                int diff = size-maxSize;
                index = l+diff;
            }
            while(((r-index+1) >= minSize) && ((r-index+1) <= maxSize))
            {
                string str = s.substr(index , r-index+1);
                mpp[str]++;
                index++;
            }
            r++;
        }
        int maxi = 0;
        for(auto &it : mpp)
        {
            maxi = max(maxi , it.second);
        }
        return maxi;
    }
};