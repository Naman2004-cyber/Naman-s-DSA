class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int mask = 0;
        int count = 1 , ans = 0;
        sort(reservedSeats.begin() , reservedSeats.end());
        int curr = reservedSeats[0][0];
        for(int i = 0 ; i<reservedSeats.size() ; i++){
            if(reservedSeats[i][0] == curr) mask |= (1 << reservedSeats[i][1]);
            else{
                count++;
                int first = 0 , second = 0 , third = 0;
                if((mask & (1<<2)) == 0 && (mask & (1<<3)) == 0 && (mask & (1<<4)) == 0 && (mask & (1<<5)) == 0) first = 1;
                if((mask & (1<<4)) == 0 && (mask & (1<<5)) == 0 && (mask & (1<<6)) == 0 && (mask & (1<<7)) == 0) second = 1;
                if((mask & (1<<6)) == 0 && (mask & (1<<7)) == 0 && (mask & (1<<8)) == 0 && (mask & (1<<9)) == 0) third = 1;
                if(first == 1){
                    if(third == 1) ans+=2;
                    else ans++;
                }
                else if(second == 1 || third == 1) ans++;
                curr = reservedSeats[i][0];
                mask = 0;
                mask |= (1 << reservedSeats[i][1]);
            }
        }
        int first = 0 , second = 0 , third = 0;
                if((mask & (1<<2)) == 0 && (mask & (1<<3)) == 0 && (mask & (1<<4)) == 0 && (mask & (1<<5)) == 0) first = 1;
                if((mask & (1<<4)) == 0 && (mask & (1<<5)) == 0 && (mask & (1<<6)) == 0 && (mask & (1<<7)) == 0) second = 1;
                if((mask & (1<<6)) == 0 && (mask & (1<<7)) == 0 && (mask & (1<<8)) == 0 && (mask & (1<<9)) == 0) third = 1;
                if(first == 1){
                    if(third == 1) ans+=2;
                    else ans++;
                }
                else if(second == 1 || third == 1) ans++;
        return ans + ((n - count)*2);
    }
};