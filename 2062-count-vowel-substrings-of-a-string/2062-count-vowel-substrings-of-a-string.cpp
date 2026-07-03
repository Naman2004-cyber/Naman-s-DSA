class Solution {
public:
    int countVowelSubstrings(string word) {
        int lastseen_a = -1;
        int lastseen_e = -1;
        int lastseen_i = -1;
        int lastseen_o = -1;
        int lastseen_u = -1;
        int count = 0;
        int l = 0;
        int r = 0;
        while(r < word.size())
        {
            int flag = 0;
            if(word[r] == 'a'){
                lastseen_a = r;
            }
            else if(word[r] == 'e')
            {
                lastseen_e = r;
            }
            else if(word[r] == 'i')
            {
                lastseen_i = r;
            }
            else if(word[r] == 'o')
            {
                lastseen_o = r;
            }
            else if(word[r] == 'u')
            {
                lastseen_u = r;
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
            mini = min(mini , lastseen_a);
            mini = min(mini , lastseen_e);
            mini = min(mini , lastseen_i);
            mini = min(mini , lastseen_o);
            mini = min(mini , lastseen_u);
            if(mini >= l && mini >= 0) count+=(mini-l+1);
            r++;
        } 
        return count;
    }
};