class Solution {
public:
    int off_set = 72;
    long long dp[16][16][151][2][2];
    long long doit(int idx , int len , int diff , bool tight , bool started , string &str){
        if(idx == str.size()){
            if(started && (len >= 2) && (diff == 0)){
                return 1;
            }
            return 0;
        }
        if(dp[idx][len][diff+off_set][tight][started] != -1) return dp[idx][len][diff+off_set][tight][started];
        int limit = tight ? str[idx]-'0' : 9;
        long long ans = 0;
        for(int digit = 0 ; digit<=limit ; digit++){
            int nextStarted = started || (digit != 0);
            int nextTight = tight && (digit == limit);
            if(!nextStarted){
                ans+=doit(idx+1 , len , diff , nextTight , false , str);
            }
            else{
                int new_diff = diff;
                if((len+1)%2 == 0) new_diff+=digit;
                else new_diff-=digit;
                int new_len = len+1;
                ans+=doit(idx+1 , new_len , new_diff , nextTight ,nextStarted , str);
            }
        }
        return dp[idx][len][diff+off_set][tight][started] = ans;
    }
    long long countBalanced(long long low, long long high) {
        string strLow = to_string(low-1);
        string strHigh = to_string(high);
        memset(dp , -1 , sizeof(dp));
        long long first = doit(0 , 0 , 0 ,  true , false , strLow);
        memset(dp , -1 , sizeof(dp));
        long long second = doit(0 , 0 , 0 , true , false , strHigh);
        return second - first;
    }
};