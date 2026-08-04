class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxi = INT_MIN;
        for(int i = n-1 ; i>=0 ; i--){
            int next = i+k >= n ? 0 : energy[i+k];
            energy[i] = energy[i] + next;
            maxi = max(maxi , energy[i]);
        }
        return maxi;
    }
};