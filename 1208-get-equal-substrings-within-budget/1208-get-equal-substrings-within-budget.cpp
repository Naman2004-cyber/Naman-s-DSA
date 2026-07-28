class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxi = 0;
        int l = 0;
        int r = 0;
        int cost = 0;
        while(r < s.size()){
            cost = cost + abs(s[r]-t[r]);
            while(cost > maxCost){
                cost = cost - abs(s[l]-t[l]);
                l++;
            }
            maxi = max(maxi , r-l+1);
            r++;
        }
        return maxi;
    }
};