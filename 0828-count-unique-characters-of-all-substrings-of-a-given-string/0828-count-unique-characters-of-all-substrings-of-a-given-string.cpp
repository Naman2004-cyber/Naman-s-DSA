class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> mpp1(26 , -1);
        vector<int> justBefore(s.size() , -1);
        for(int i = 0 ;  i<s.size() ; i++)
        {
            justBefore[i] = mpp1[s[i]-'A'];
            mpp1[s[i]-'A'] = i;
        }
        // for(int i = 0 ; i<justBefore.size() ; i++)
        // {
        //     cout << justBefore[i] << " ";
        // }
        vector<int> mpp2(26 , -1);
        vector<int> justAfter(s.size() , -1);
        for(int i = s.size()-1 ; i>=0 ; i--)
        {
            justAfter[i] = mpp2[s[i]-'A'];
            mpp2[s[i]-'A'] = i;
        } 
        // for(int i = 0 ; i<justAfter.size() ; i++)
        // {
        //     cout << justAfter[i] << " ";
        // }

        int ans = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            int first = justBefore[i] == -1 ? i+1 : i - justBefore[i];
            int second = justAfter[i] == -1 ? s.size()-i : justAfter[i] - i;
            ans = ans + (first * second);
        }

        return ans;

    }
};