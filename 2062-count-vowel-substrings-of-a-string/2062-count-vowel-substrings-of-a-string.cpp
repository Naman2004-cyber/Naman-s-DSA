class Solution {
public:
    int countVowelSubstrings(string word) {
        vector<int> lastseen(26 , -1);
        int count = 0;
        int l = 0;
        int r = 0;
        while(r < word.size())
        {
            int flag = 0;
            if(word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u')
            {
                lastseen[word[r]-97] = r;
            }
            else
            {
                flag = 1;
            }
            if(flag == 1)
            {
                l = r;
                l++;
                r++;
                continue;
            }
            int mini = INT_MAX;
            for(int i = 0 ; i<26 ; i++)
            {
                char ch = 'a' + i;
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    mini = min(mini , lastseen[ch-97]);
                }
            }
            if(mini >= l) count+=(mini-l+1);
            r++;
        } 
        return count;
    }
};