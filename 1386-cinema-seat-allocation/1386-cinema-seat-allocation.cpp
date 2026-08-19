class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , unordered_set<int>> mpp;
        for(int i = 0 ; i<reservedSeats.size() ; i++){
            mpp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int count = 0;
        for(auto &it : mpp){
            int first = 1 , second = 1 ,  third = 1;
            for(auto &a : it.second){
                if(a == 2 || a == 3 || a == 4 || a == 5) first = 0;
                if(a == 4 || a == 5 || a == 6 || a == 7) second = 0;
                if(a == 6 || a == 7 || a == 8 || a == 9) third = 0;
            }
            if(first == 1){
                if(third == 1) count+=2;
                else count++;
            }
            else if(second == 1 || third == 1) count++;
        }
        return count + ((n - mpp.size())*2);
    }
};