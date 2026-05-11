class Solution {
  public:

    int recursion(vector<vector<int>> &dp, string &s1, string &s2, int index1, int index2){
        if(index1<0 || index2<0){
            return 0;
        }
        
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int left = 0;
        int right = 0;
        
        if(s1[index1]==s2[index2]) {
            return dp[index1][index2] = 1 + recursion(dp, s1, s2, index1-1, index2-1);
        } 
        if(s1[index1]!=s2[index2]){
            left = recursion(dp, s1, s2, index1, index2-1);
            right = recursion(dp, s1, s2, index1-1, index2);
        } 
        
        return dp[index1][index2] = max(left, right);
        
    }

    int longestPalinSubseq(string &s) {
        string rev = s;
        reverse(s.begin(), s.end()); 
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return recursion(dp, s, rev, s.size()-1, s.size()-1);
    }
};