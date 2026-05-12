class Solution {
  public:

    int recursion(vector<vector<int>> &dp, string &s1, int index1, int index2){
        if(index1>index2){
            return 0;
        }

        if(index1==index2) return 1;
        
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int left = 0;
        int right = 0;
        
        if(s1[index1]==s1[index2]) {
            return dp[index1][index2] = 2 + recursion(dp, s1, index1+1, index2-1);
        } 
            left = recursion(dp, s1, index1, index2-1);
            right = recursion(dp, s1, index1+1, index2);
        
        
        return dp[index1][index2] = max(left, right);
        
    }


    int longestPalindromeSubseq(string s) {
        // string rev = s;
        // reverse(s.begin(), s.end()); 
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return recursion(dp, s, 0, s.size()-1);
    }
};