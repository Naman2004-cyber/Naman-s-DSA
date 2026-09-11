class Solution {
public:
    int dp[300][300];
    int doit(int idx , int start , unordered_map<string , int> &mpp , string &s){
        if(idx == s.size()){
            string strNew = s.substr(start , idx-start);
            if(mpp.find(strNew) != mpp.end()) return 1;
            return 0;
        }
        if(dp[idx][start] != -1) return dp[idx][start];
        string strNew = s.substr(start , idx-start+1);
        int conti = doit(idx + 1 , start , mpp , s);
        int take = 0;
        if(mpp.find(strNew) != mpp.end()){
            take = doit(idx+1 , idx+1 , mpp , s);
        }
        return dp[idx][start] = conti || take;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , int> mpp;
        for(int i = 0 ; i<wordDict.size() ; i++) mpp[wordDict[i]]++;
        string str = "";
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , mpp , s);
    }
};