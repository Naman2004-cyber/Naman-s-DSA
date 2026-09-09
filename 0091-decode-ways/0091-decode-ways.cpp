class Solution {
public:
    int numDecodings(string s) {
        int nn = 1;
        int n = s[s.size()-1] == '0' ? 0 : 1;
        for(int i = s.size()-2 ; i>=0 ; i--){
            if(s[i] == '0'){
                nn = n;
                n = 0;
                continue;
            }
            int takeCurr = 0;
            takeCurr+=n;
            int takeNext = 0;
            if(i+1 < s.size()){
                int first = s[i] -'0' , second = s[i+1] - '0';
                if((first == 1) || (first==2 && second <= 6)) takeNext+=nn;
            }
            int curr = takeCurr + takeNext;
            nn = n;
            n = curr;
        }
        return n;
    }
};