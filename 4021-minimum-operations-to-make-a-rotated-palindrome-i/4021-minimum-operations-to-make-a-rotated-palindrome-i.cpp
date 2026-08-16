class Solution {
public:
    int minOperations(string s) {
        int mini = INT_MAX;
        int n = s.size();
        for(int i = 0 ; i<s.size() ; i++){
            reverse(s.begin()+1 , s.end());
            reverse(s.begin() , s.end());
            int l = 0;
            int r = s.size()-1;
            int count = 0;
            while(l <= r){
                int fWay = abs(s[l]-s[r]);
                char big = s[r] >= s[l] ? s[r] : s[l];
                char small = s[r] < s[l] ? s[r] : s[l];
                int sWay = ('z'-big) + (small-'a') + 1;
                count+=min(fWay , sWay);
                l++;
                r--;
            }
            count = (i == n-1) ? count : count+i+1;
            mini = min(mini , count);
        }
        return mini;
    }
};