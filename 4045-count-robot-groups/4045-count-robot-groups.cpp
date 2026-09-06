class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int mini = speed[speed.size()-1];
        int minPosition = position[position.size()-1];
        int count = 1;
        for(int i = speed.size()-2 ; i>=0 ; i--){
            if((speed[i] <= mini) && (minPosition-position[i] > distance)){
                count++;
                mini = speed[i];
            }
            minPosition = position[i];
        }
        return count;
    }
};