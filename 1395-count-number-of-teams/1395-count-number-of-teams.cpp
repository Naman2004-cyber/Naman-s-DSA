class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        for(int i = 1 ; i<n-1 ; i++){
            int smallRight = 0 , largeRight = 0;
            for(int j = i+1 ; j<n ; j++){
                if(rating[j] > rating[i]) largeRight++;
                if(rating[j] < rating[i]) smallRight++;
            }
            int smallLeft = 0;
            int largeLeft = 0;
            for(int j = 0 ; j<i ; j++){
                if(rating[j] > rating[i]) largeLeft++;
                if(rating[j] < rating[i]) smallLeft++;
            }
            count+=((smallLeft * largeRight) + (largeLeft * smallRight));
        }
        return count;
    }
};