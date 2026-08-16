class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int count = requests[0];
        for(int i = 0 ; i<requests.size()-1 ; i++) count+=(abs(requests[i+1] - requests[i]));
        return count;
    }
};