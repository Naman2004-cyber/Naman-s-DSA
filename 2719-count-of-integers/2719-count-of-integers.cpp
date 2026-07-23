class Solution {
public:
    int mod = 1e9+7;
    int dp[23][401][2][2];
    int doit(int idx , int sum , bool tight , bool started , string &str , int &min_sum , int &max_sum){
        if(idx == str.size()){
            if(sum >= min_sum && sum <= max_sum) return 1;
            return 0;
        }
        if(dp[idx][sum][tight][started] != -1) return dp[idx][sum][tight][started];
        int limit = tight ? str[idx]-'0' : 9;
        int ans = 0;
        for(int digit = 0 ; digit <= limit ; digit++){
            bool nextTight = tight && (digit == limit);
            bool nextStarted = started || (digit != 0);
            if(!nextStarted){
                ans = (ans + doit(idx+1 , sum , nextTight , false , str , min_sum , max_sum))%mod;
            }
            else{
                int new_sum = sum + digit;
                if(new_sum <= max_sum){
                    ans = (ans + doit(idx+1 , new_sum , nextTight , nextStarted , str , min_sum , max_sum))%mod;
                }
            }
        }
        return dp[idx][sum][tight][started] = ans;
    }
    bool checkLow(string &str , int &min_sum , int &max_sum){
        int sum = 0;
        for(int i = 0 ; i<str.size() ; i++){
            int use = str[i]-'0';
            sum+=use;
        }
        if(sum >= min_sum && sum <= max_sum) return true;
        return false;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp , -1 , sizeof(dp));
        int first = doit(0 , 0 , true , false , num1 , min_sum , max_sum);
        memset(dp , -1 , sizeof(dp));
        int second = doit(0 , 0 , true , false , num2 , min_sum , max_sum);
        int ans = (second - first + mod)%mod;
        if(checkLow(num1 , min_sum , max_sum)) ans++;
        ans = ans%mod;
        return ans;
    }
};