class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int , int>> cars;
        for(int i = 0 ; i<position.size() ; i++){
            cars.push_back({position[i] , speed[i]});
        }
        sort(cars.begin() , cars.end());
        int count = 1;
        double miniTime = (target -  cars[cars.size()-1].first)/(double)cars[cars.size()-1].second;
        for(int i = cars.size()-2 ; i>=0 ; i--){
            double timeNow = (target -  cars[i].first)/(double)cars[i].second;
            if(timeNow > miniTime){
                count++;
                miniTime = timeNow;
            }
        }
        return count;
    }
};