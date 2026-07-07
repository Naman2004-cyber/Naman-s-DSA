class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n != 1)
        {
            int a = n%3;
            if(a > 1) return false;
            n = n/3;
        }
        return true;
    }
};