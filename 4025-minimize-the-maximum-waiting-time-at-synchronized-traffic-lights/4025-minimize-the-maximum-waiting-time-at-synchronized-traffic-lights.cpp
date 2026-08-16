class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi = 0;
        int maxLight = lights[0];
        for(int i = 1 ; i<lights.size() ; i++) maxLight = max(maxLight , lights[i]);
        for(int i = 0 ; i<arrivalTime.size() ; i++){
            int r = arrivalTime[i]%period;
            if(r >= maxLight) maxi = max(maxi , period-r);
        }
        return maxi;
    }
};