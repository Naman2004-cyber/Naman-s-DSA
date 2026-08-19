class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<int> check(11 , 0);
        int count = 1 , ans = 0;
        sort(reservedSeats.begin() , reservedSeats.end());
        int curr = reservedSeats[0][0];
        for(int i = 0 ; i<reservedSeats.size() ; i++){
            if(reservedSeats[i][0] == curr) check[reservedSeats[i][1]] = 1;
            else{
                count++;
                int first = 1 , second = 1 , third = 1;
                if(check[2] == 1 || check[3] == 1 || check[4] == 1 || check[5] == 1) first = 0;
                if(check[4] == 1 || check[5] == 1 || check[6] == 1 || check[7] == 1) second = 0;
                if(check[6] == 1 || check[7] == 1 || check[8] == 1 || check[9] == 1) third = 0;
                if(first == 1){
                    if(third == 1) ans+=2;
                    else ans++;
                }
                else if(second == 1 || third == 1) ans++;
                curr = reservedSeats[i][0];
                fill(check.begin() , check.end() , 0);
                check[reservedSeats[i][1]] = 1;
            }
        }
        int first = 1 , second = 1 , third = 1;
                if(check[2] == 1 || check[3] == 1 || check[4] == 1 || check[5] == 1) first = 0;
                if(check[4] == 1 || check[5] == 1 || check[6] == 1 || check[7] == 1) second = 0;
                if(check[6] == 1 || check[7] == 1 || check[8] == 1 || check[9] == 1) third = 0;
                if(first == 1){
                    if(third == 1) ans+=2;
                    else ans++;
                }
                else if(second == 1 || third == 1) ans++;
        return ans + ((n - count)*2);
    }
};