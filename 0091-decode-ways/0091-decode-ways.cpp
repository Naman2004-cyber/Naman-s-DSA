class Solution {
public:
    int doit(int idx , string &s , vector<int> &dp){
        if(s[idx] == '0') return 0;
        if(idx >= s.size()) return 1;
        if(dp[idx] != -1) return dp[idx];
        int takeCurr = 0 , takeNext = 0;
        takeCurr+=doit(idx+1 , s , dp);
        if(idx+1 < s.size()){
            int first = s[idx] -'0' , second = s[idx+1] - '0';
            if((first == 1) || (first==2&&second <= 6)) takeNext+=doit(idx+2,s , dp);
        }
        return dp[idx] = takeCurr + takeNext;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() , -1);
        return doit(0 , s , dp);
    }
};