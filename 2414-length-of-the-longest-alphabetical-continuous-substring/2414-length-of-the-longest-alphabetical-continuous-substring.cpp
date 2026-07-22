class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxi = 1;
        int count = 1;
        for(int i = 1 ; i<s.size() ; i++){
            if(s[i] == s[i-1]+1){
                count++;
            }
            else{
                maxi = max(maxi , count);
                count = 1;
            }
        }
        maxi = max(maxi , count);
        return maxi;
    }
};