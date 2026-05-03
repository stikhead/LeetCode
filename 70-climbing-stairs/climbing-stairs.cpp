// NOTE FOR FUTRE SELF

// However, to make that jump to DP, there is one major habit from backtracking that you have to break first.

// The Shift: Return Values vs. Reference Variables
// In backtracking, you usually pass an ans variable by reference (int &ans) and modify it when you hit a base case.

// In DP, your recursive function MUST return the answer.
// Why? Because to use a cache (memoization), the function has to evaluate to a specific number so we can save it. We want to say memo[steps] = recursion(...).


class Solution {
public:
    int recursion(vector<int> &dp, int &n, int steps){
        if(steps==n){
            return 1;
        }

        if(steps>n){
            return 0;
        }

        if(dp[steps] != -1) {
            return dp[steps];
        }

        dp[steps] =  recursion(dp, n, steps + 1) + recursion(dp, n, steps + 2);
        return dp[steps]; 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int steps = 0;
        return recursion(dp, n, steps);
        

    }
};