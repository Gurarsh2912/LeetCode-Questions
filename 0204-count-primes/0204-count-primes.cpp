class Solution {
public:
    // sieve of eratosthenes
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        int cnt = 0;

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {

            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }

            }
        }
        for(int i=0; i<n; i++){
            if (isPrime[i]) cnt++;
        }
        return cnt;
    }
};