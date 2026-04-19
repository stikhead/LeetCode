class Solution {
public:
    // Palindrome helper remains exactly the same
    bool isPalindrome(const string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    // Now returns the minimum cuts required from 'index' to the end of the string
    int solve(const string &input, int index, vector<int> &memo) {
        // Base case: If we reach the end, no more cuts are needed
        if (index == input.size()) {
            return 0;
        }

        // If we've already calculated the answer for this suffix, return it instantly
        if (memo[index] != -1) {
            return memo[index];
        }

        int min_cuts = INT_MAX;

        // Try all possible prefixes starting from 'index'
        for (int i = index; i < input.size(); i++) {
            if (isPalindrome(input, index, i)) {
                // If s[index...i] is a palindrome, we make 1 cut here.
                // Then we recursively find the min cuts for the remaining string (i + 1)
                int cuts_for_rest = solve(input, i + 1, memo);
                
                // We add 1 to represent the cut we just made (unless we are at the very end of the string)
                int total_cuts = (i == input.size() - 1) ? 0 : 1 + cuts_for_rest;
                
                min_cuts = min(min_cuts, total_cuts);
            }
        }

        // Store the result before returning
        return memo[index] = min_cuts;
    }

    int minCut(string s) {
        int n = s.size();
        // Initialize memoization array with -1
        vector<int> memo(n, -1);
        return solve(s, 0, memo);
    }
};