class Solution {
public:
    int dp[101][11][2][2];
    int mod = 1e9+7;
    int doit(int pos , int prevDigit , bool tight , bool started , string &str){
        if(pos == str.size()) return started == true;
        if(dp[pos][prevDigit][tight][started] != -1) return dp[pos][prevDigit][tight][started];
        int limit = tight ? str[pos]-'0' : 9;
        int ans = 0;
        for(int digit = 0 ; digit<=limit ; digit++){
            bool nextTight = tight && (digit == str[pos]-'0');
            bool nextStarted = started || (digit != 0);
            if(!nextStarted){
                ans = (ans + doit(pos+1 , 10 , nextTight , false , str))%mod;
            }
            else{
                if(!started || abs(prevDigit-digit) == 1){
                    ans = (ans + doit(pos+1 , digit , nextTight , nextStarted , str))%mod;
                }
            }
        }
        return dp[pos][prevDigit][tight][started] = ans;
    }
    bool isValid(string str){
        for(int i = 0 ; i<str.size()-1 ; i++){
            if(abs(str[i] - str[i+1]) != 1) return false;
        }
        return true;
    }
    int countSteppingNumbers(string low , string high) {
        memset(dp , -1 , sizeof(dp));
        int first = doit(0 , 10 , true , false , low);
        memset(dp , -1 , sizeof(dp));
        int second = doit(0 , 10 , true , false , high);
        int ans = (second - first + mod)%mod;
        if(isValid(low)) ans++;
        ans = ans%mod;
        return ans;
    }
};