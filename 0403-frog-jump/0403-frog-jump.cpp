class Solution {
public:
    unordered_map<long long , bool> dp;
    bool doit(long long idx , long long prev , set<int>& st , int end){
        if(idx == end) return true;
        long long key = (idx << 32) | prev;
        if(dp.count(key)) return dp[key];
        bool first = false;
        bool second = false;
        bool third = false;
        if(prev-1 > 0 && st.count(idx + prev-1)){
            first = doit(idx+prev-1 , prev-1 , st , end);
        }
        if(st.count(idx+prev)){
            second = doit(idx+prev , prev , st , end);
        }
        if(st.count(idx+prev+1)){
            third = doit(idx+prev+1 , prev+1 , st , end);
        }
        return dp[key] = first || second || third;
    }
    bool canCross(vector<int>& stones) {
        set<int> st;
        st.insert(stones.begin() , stones.end());
        if(!st.count(1)) return false;
        return doit(1 , 1 , st , stones[stones.size()-1]);
    }
};