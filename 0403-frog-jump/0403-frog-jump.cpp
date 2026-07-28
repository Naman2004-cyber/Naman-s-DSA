class Solution {
public:
    unordered_map<long long , bool> positions;
    unordered_map<long long , bool> dp;
    bool doit(long long idx , long long prevJumps , int last){
        if(idx == last) return true;
        long long key = (idx << 32) | prevJumps;
        if(dp.count(key)) return dp[key];
        bool prev_minus = false;
        bool prev_equal = false;
        bool prev_plus = false;
        if((prevJumps-1 > 0) && positions.find(idx + prevJumps -1) != positions.end()){
            prev_minus = doit(idx+prevJumps-1 , prevJumps-1 , last);
        }
        if((prevJumps > 0) && positions.find(idx + prevJumps) != positions.end()){
            prev_equal = doit(idx+prevJumps , prevJumps , last);
        }
        if((prevJumps+1 > 0) && positions.find(idx + prevJumps + 1) != positions.end()){
            prev_plus = doit(idx+prevJumps+1 , prevJumps+1 , last);
        }
        return dp[key] = prev_minus || prev_equal || prev_plus;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        for(int i = 0 ; i<stones.size() ; i++) positions[stones[i]] = true;
        return doit(1 , 1 , stones[stones.size()-1]);
    }
};