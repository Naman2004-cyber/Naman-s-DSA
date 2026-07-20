class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            int countSmallRight = 0;
            int countLargeRight = 0;
            for(int j = i+1 ; j<n ; j++){
                if(rating[j] > rating[i]) countLargeRight++;
                if(rating[j] < rating[i]) countSmallRight++;
            }
            int countSmallLeft = 0;
            int countLargeLeft = 0;
            for(int j = 0 ; j<i ; j++){
                if(rating[j] > rating[i]) countLargeLeft++;
                if(rating[j] < rating[i]) countSmallLeft++;
            }
            count+=(countSmallLeft * countLargeRight);
            count+=(countLargeLeft * countSmallRight);
        }
        return count;
    }
};