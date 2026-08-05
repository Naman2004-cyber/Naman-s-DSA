class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n);
        for(int i = 0 ; i<shifts.size() ; i++){
            int l = shifts[i][0];
            int r = shifts[i][1];
            int dir = shifts[i][2];
            if(dir == 1){
                diff[l]+=1;
                if(r+1 < n) diff[r+1]-=1;
            }
            else{
                diff[l]-=1;
                if(r+1 < n) diff[r+1]+=1;
            }
        }
        vector<int> prefix(n);
        prefix[0] = diff[0];
        for(int i = 1 ; i<n ; i++){
            prefix[i] = prefix[i-1] + diff[i];
        }
        for(int i = 0 ; i<n ; i++){
            if(prefix[i] >= 0){
                int naya = prefix[i]%26;
                int charVal = s[i] + naya;
                if(charVal > 122){
                    int diff = charVal - 122;
                    s[i] = 'a' + diff - 1;
                }
                else s[i]+=naya;
            }
            else{
                int naya = abs(prefix[i]);
                naya = naya%26;
                int charVal = s[i] - naya;
                if(charVal < 97){
                    int diff = 97 - charVal;
                    s[i] = 'z' - diff + 1;
                }
                else s[i]-=naya;
            }
        }
        return s;
    }
};