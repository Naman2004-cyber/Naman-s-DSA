class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for(int i = 0 ; i<target.size()-1 ; i++)
        {
            if(target[i+1] > target[i]) ans+=(target[i+1] - target[i]);
        }
        return ans;
    }
};