class Solution {
public:
    long long appealSum(string s) {
        vector<int> mpp1(26 , -1);
        vector<int> justBefore(s.size() , -1);
        vector<int> firstOccu(26 , -1);
        for(int i = 0 ;  i<s.size() ; i++)
        {
            if(firstOccu[s[i]-'a'] == -1) firstOccu[s[i]-'a'] = i;
            justBefore[i] = mpp1[s[i]-'a'];
            mpp1[s[i]-'a'] = i;
        }
        long long ans = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            ans+=(s.size()-i);
        }
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(justBefore[i] == -1)
            {
                ans+=i;
            }
            else
            {
                ans+=(i-justBefore[i]-1);
            }
        }
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(justBefore[i] == -1)
            {
                ans = ans + (i*(s.size()-i-1));
            }
            else 
            {
                ans = ans + ((i-justBefore[i]-1)*(s.size()-i-1));
            }
        }
        return ans;
    }
};