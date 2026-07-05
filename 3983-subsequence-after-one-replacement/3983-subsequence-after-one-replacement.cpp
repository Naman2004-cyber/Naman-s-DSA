class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> pref(n , -1);
        vector<int> suff(n , -1);

        int j = 0;
        for(int i = 0 ; i<n ; i++)
            {
                while(j < m && t[j] != s[i]) j++;
                if(j == m) break;
                pref[i] = j;
                j++;
            }
        if(pref[n-1] != -1) return true;
        j = m-1;
        for(int i = n-1 ; i>=0 ; i--)
            {
                while(j >= 0 && t[j] != s[i]) j--;
                if(j < 0) break;
                suff[i] = j;
                j--;
            }
        for(int i = 0 ; i<n ; i++)
            {
                int left = (i==0) ? -1 : pref[i-1];
                if(i > 0 && left == -1) continue;
                int right = (i == n-1) ? m : suff[i+1];
                if(i < n-1 && right == -1) continue;
                if(left+1 < right) return true;
            }
        return false;
    }
};