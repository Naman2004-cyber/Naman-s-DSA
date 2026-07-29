class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0 ; i<=num ; i++){
            int rev = 0;
            int use = i;
            while(use != 0){
                int a = use%10;
                rev = rev*10 + a;
                use = use/10;
            }
            if(rev+i == num) return true;
        }
        return false;
    }
};