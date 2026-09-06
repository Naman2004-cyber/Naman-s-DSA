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
        stack<int> st;
        for(int i = 0 ; i<spee.size() ; i++){
            while(!st.empty() && (spee[st.top()] > spee[i])){
                st.pop();
            }
            st.push(i);
        }
        return st.size();
    }
};