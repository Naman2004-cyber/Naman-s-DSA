class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int start = -1;
        int end = -1;
        int l = 0;
        int r = 0;
        int count1 = 0;
        int mini = INT_MAX;
        while(r < s.size()){
            if(s[r] == '1') count1++;
            while(count1 > k || (count1 == k && s[l] == '0')){
                 if(s[l] == '1') count1--;
                 l++;
            }
            if(count1 == k){
                if(r-l+1 < mini){
                    mini = r-l+1;
                    start = l;
                    end = r;
                }
                else if(r-l+1 == mini){
                    string prev = s.substr(start , end-start+1);
                    string curr = s.substr(l , r-l+1);
                    if(curr < prev){
                        start = l;
                        end = r;
                    }
                }
                
            }
            r++;
        }
        if(start == -1 || end == -1) return "";
        string ans = s.substr(start , end-start+1);
        return ans;
    }
};