class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        int req = num%10;
        int sum = 0;
        for(int i = 1 ; i<=10 ; i++){
            if(i*k > num) return -1;
            if((k*i)%10 == num%10) return i;
        }
        return -1;
    }
};