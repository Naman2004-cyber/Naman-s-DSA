class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even = 2;
        int odd = 1;
        int sumEven = 0;
        int sumOdd = 0;
        for(int i = 0 ; i<n ; i++){
            sumEven+=even;
            sumOdd+=odd;
            even+=2;
            odd+=2;
        }
        int ans = gcd(sumEven , sumOdd);
        return ans;
    }
};