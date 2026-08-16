class Solution {
public:
    int racecar(int target) {
        int position = 0;
        int speed = 1;
        queue<pair<int , int>> qt;
        qt.push({position , speed});
        set<pair<int ,int>> st;
        st.insert({position , speed});
        int level = 0;
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                auto it = qt.front();
                qt.pop();
                int currPosition = it.first;
                int currSpeed = it.second;
                if(currPosition == target) return level;
                int newPositionA = currPosition + currSpeed;
                int newSpeedA = currSpeed*2;
                if(abs(newPositionA) <= (2*target) && st.count({newPositionA , newSpeedA}) == 0){
                    qt.push({newPositionA , newSpeedA});
                    st.insert({newPositionA , newSpeedA});
                }
                int newSpeedR = currSpeed < 0 ? 1 : -1;
                if(st.count({currPosition , newSpeedR}) == 0){
                    qt.push({currPosition , newSpeedR});
                    st.insert({currPosition , newSpeedR});
                }
            }
            level++;
        }
        return 0;
    }
};