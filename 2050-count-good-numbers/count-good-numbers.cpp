class Solution {
public:
    long long power(long long base, long long exp) {
        long long mod = 1e9 + 7;
        long long res = 1;
        base = base % mod;
        
        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1; 
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long even_indices = (n + 1) / 2;
        long long odd_indices = n / 2;

        return (power(5, even_indices) * power(4, odd_indices)) % mod;
    }
};