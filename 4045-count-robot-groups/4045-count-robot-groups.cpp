class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<int> pos;
        vector<int> spee;
        pos.push_back(position[0]);
        spee.push_back(speed[0]);
        for(int i = 1 ; i<position.size() ; i++){
            if(position[i]-pos.back() <= distance) {
                pos.back() = position[i];
                spee.back() = speed[i];
            }
            else{
                pos.push_back(position[i]);
                spee.push_back(speed[i]);
            }
        }
        int mini = spee[spee.size()-1];
        int count = 1;
        for(int i = spee.size()-2 ; i>=0 ; i--){
            if(spee[i] <= mini){
                count++;
                mini = spee[i];
            }
        }
        return count;
    }
};