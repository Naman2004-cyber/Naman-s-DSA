class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;
        while(n != 0)
        {
            int a = n%10;
            if(a != 0)
            {
                sum+=a;
                num = num*10 + a;
            }
            n = n/10;
        }
        long long rev = 0;
        while(num != 0)
        {
            int a = num%10;
            rev = rev*10 + a;
            num = num/10;
        }
        long long ans = 1LL * rev * sum;
        // cout << rev;
        return ans;
    }
};