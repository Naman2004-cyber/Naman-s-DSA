class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<reservedSeats.size() ; i++){
            mpp[reservedSeats[i][0]] |= (1 << reservedSeats[i][1]);
        }
        int ans = 0;
        for(auto &it : mpp){
            int first = 0 , second = 0 , third = 0;
            int mask = it.second;
            if((mask & (1<<2)) == 0 && (mask & (1<<3)) == 0 && (mask & (1<<4)) == 0 && (mask & (1<<5)) == 0) first = 1;
                if((mask & (1<<4)) == 0 && (mask & (1<<5)) == 0 && (mask & (1<<6)) == 0 && (mask & (1<<7)) == 0) second = 1;
                if((mask & (1<<6)) == 0 && (mask & (1<<7)) == 0 && (mask & (1<<8)) == 0 && (mask & (1<<9)) == 0) third = 1;
                if(first == 1){
                    if(third == 1) ans+=2;
                    else ans++;
                }
                else if(second == 1 || third == 1) ans++;
        }
        return ans + ((n - mpp.size())*2);
    }
};