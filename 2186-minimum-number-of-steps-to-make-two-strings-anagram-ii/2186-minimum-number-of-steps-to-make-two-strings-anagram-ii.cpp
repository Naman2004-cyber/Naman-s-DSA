class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mppS;
        unordered_map<char , int> mppT;
        for(int i = 0 ; i<s.size() ; i++) mppS[s[i]]++;
        for(int i = 0 ; i<t.size() ; i++) mppT[t[i]]++;
        int countS = 0;
        int countT = 0;
        for(auto &it : mppS){
            char chS = it.first;
            int timesS = it.second;
            if(mppT.find(chS) == mppT.end()){
                countS+=timesS;
            }
            else{
                if(timesS > mppT[chS]){
                    countS+=(timesS - mppT[chS]);
                }
            }
        }
        for(auto &it : mppT){
            char chT = it.first;
            int timesT = it.second;
            if(mppS.find(chT) == mppS.end()){
                countT+=timesT;
            }
            else{
                if(timesT > mppS[chT]){
                    countT+=(timesT - mppS[chT]);
                }
            }
        }
        return countS+countT;
    }
};