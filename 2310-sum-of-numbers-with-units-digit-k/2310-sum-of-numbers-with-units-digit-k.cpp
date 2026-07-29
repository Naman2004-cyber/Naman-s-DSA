class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        if(num < k) return -1;
        int req = num%10;
        int sum = 0;
        for(int i = 0 ; i<1000 ; i++){
            sum+=k;
            if(sum > num) return -1;
            int aval = sum%10;
            if(aval == req) return i+1;
        }
        return -1;
    }
};