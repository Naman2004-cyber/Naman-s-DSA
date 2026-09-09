class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long count = 0;
        if(n > (1e3-1))
        {
            if(n < 1e6) count+=(n - (1e3-1));
            else count+=((1e6-1) - (1e3-1));
        }
        if(n > (1e6-1))
        {
            if(n < 1e9) count+=(n - (1e6-1))*2;
            else count+=((1e9-1) - (1e6-1))*2;
        }
        if(n > (1e9-1))
        {
            if(n < 1e12) count+=(n-(1e9-1))*3;
            else count+=((1e12-1) - (1e9-1))*3;
        }
        if(n > (1e12-1))
        {
            if(n < 1e15) count+=(n-(1e12-1))*4;
            else count+=((1e15-1) - (1e12-1))*4;
        }
        if(n > (1e15-1)) count+=(n - (1e15-1))*5;
        return count;
    }
};