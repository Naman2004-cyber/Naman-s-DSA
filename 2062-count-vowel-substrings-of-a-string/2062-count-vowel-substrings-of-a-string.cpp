class Solution {
public:
    int countVowelSubstrings(string word) {
        // int lastseen_a = -1;
        // int lastseen_e = -1;
        // int lastseen_i = -1;
        // int lastseen_o = -1;
        // int lastseen_u = -1;
        vector<int> lastseen(26 , -1);
        int count = 0;
        int l = 0;
        int r = 0;
        while(r < word.size())
        {
            int flag = 0;
            // if(word[r] == 'a'){
            //     lastseen_a = r;
            // }
            // else if(word[r] == 'e')
            // {
            //     lastseen_e = r;
            // }
            // else if(word[r] == 'i')
            // {
            //     lastseen_i = r;
            // }
            // else if(word[r] == 'o')
            // {
            //     lastseen_o = r;
            // }
            // else if(word[r] == 'u')
            // {
            //     lastseen_u = r;
            // }
            // else
            // {
            //     flag = 1;
            // }
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
            mini = min(mini , lastseen['a'-97]);
            mini = min(mini , lastseen['e'-97]);
            mini = min(mini , lastseen['i'-97]);
            mini = min(mini , lastseen['o'-97]);
            mini = min(mini , lastseen['u'-97]);
            if(mini >= l && mini >= 0) count+=(mini-l+1);
            r++;
        } 
        return count;
    }
};