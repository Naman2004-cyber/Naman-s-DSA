class Solution {
public:
    bool checker(int element , int m , int n  , int k){
        int count = 0;
        for(int i = 1 ; i<=m ; i++){
            int use = min(n , element/i);
            count+=use;
        }
        if(count >= k) return true;
        return false;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int ans = -1;
        while(low <= high){
            int mid = low + ((high-low)/2);
            if(checker(mid , m , n , k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};