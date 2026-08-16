class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi = 0;
        sort(lights.begin() , lights.end());
        for(int i = 0 ; i<arrivalTime.size() ; i++){
            int r = arrivalTime[i]%period;
        int idx = upper_bound(lights.begin() , lights.end() , r) - lights.begin();
            if(idx == lights.size()) maxi = max(maxi , period-r);
        }
        return maxi;
    }
};