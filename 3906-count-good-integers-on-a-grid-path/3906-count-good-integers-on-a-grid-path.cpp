class Solution {
public:
    long long dp[16][11][2];
    string getpad(long long a){
        string str = to_string(a);
        while(str.size() < 16){
            str = '0' + str;
        }
        return str;
    }
    long long doit(int idx , int prev , bool tight ,  unordered_set<int> &dir , string &str){
        if(idx == 16) return 1;
        if(dp[idx][prev][tight] != -1) return dp[idx][prev][tight];
        int limit = tight ? str[idx]-'0' : 9;
        long long ans = 0;
        for(int digit = 0 ; digit<=limit ; digit++){
            bool nextTight = tight && (digit == limit);
                if(dir.find(idx) == dir.end()){
                    ans+=doit(idx+1 , prev , nextTight , dir , str);
                }
                else if(prev == 10 || prev <= digit){
                    ans+=doit(idx+1 , digit , nextTight , dir , str);
                }
        }
        return dp[idx][prev][tight] = ans;
    }
    int curr = 0;
    bool checkLow(string &low , string directions){
        for(int i = 0 ; i<directions.size() ; i++){
            int first = low[curr];
            int useIdx;
            if(directions[i] == 'D') useIdx = curr+4;
            else useIdx = curr+1;
            int second = low[useIdx];
            if(first > second) return false;
            curr = useIdx;
        }
        return true;
    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        string low = getpad(l);
        string high = getpad(r);
        unordered_set<int> dir;
        dir.insert(0);
        int curr = 0;
        for(int i = 0 ; i<directions.size() ; i++){
            if(directions[i] == 'D') {
                curr+=4;
            }
            else {
                curr+=1;
            }
            dir.insert(curr);
        }
        memset(dp , -1 , sizeof(dp));
        long long first = doit(0 , 10 , true , dir , low);
        memset(dp , -1 , sizeof(dp));
        long long second = doit(0 , 10 , true , dir , high);
        long long ans = second-first;
        if(checkLow(low , directions)) ans++;
        return ans;
    }
};