// every prime number till n will have at least one prime factor till root(n)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1 , true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 2 ; i*i<=n ; i++)
        {
            if(primes[i])
            {
                for(int j = i*i ; j<=n ; j+=i) primes[j] = false;
            }
        }
        int count = 0;
        for(int i = 0 ; i<n ; i++) if(primes[i]) count++;
        return count;
    }
};