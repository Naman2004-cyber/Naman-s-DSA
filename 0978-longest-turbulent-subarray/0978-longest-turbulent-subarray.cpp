class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int l = 0 , r = 1 , prevTurn = -1 , maxi = 1;
        while(r < arr.size()){
            int turn = arr[r-1] > arr[r] ? 1 : 0;
            if(turn == prevTurn){
                l = r-1;
                prevTurn = -1;
                continue;
            }
            else if(arr[r-1] == arr[r]){
                l = r;
                r++;
                prevTurn = -1;
                continue;
            }
            maxi = max(maxi , r-l+1);
            prevTurn = turn;
            r++;
        }
        return maxi;
    }
};