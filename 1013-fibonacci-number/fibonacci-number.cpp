class Solution {
public:
    int fibSeries(int n, vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fibSeries(n-1, dp) + fibSeries(n-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fibSeries(n, dp);    
    }
    // int fibSeries(int n){
    //     if(n<=1){
    //         return n;
    //     }
    //     return fibSeries(n - 1) + fibSeries(n-2);
    // }
    // int fib(int n) {
    //     return fibSeries(n);
    // }
    // int fib(int n) {
    //     long long f0 = 0;
    //     long long f1 = 1;
    //     if(n<=1) return n;
    //     long long f2;
    //     for(int i=2; i<=n; i++){
    //         f2 = f1 + f0;
    //         f0 = f1;
    //         f1 = f2;
    //     }
    //     return f1;
    // }
};