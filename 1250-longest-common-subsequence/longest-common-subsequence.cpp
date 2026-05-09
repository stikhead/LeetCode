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
            return 1 + recursion(dp, s1, s2, index1-1, index2-1);
        } 
        if(s1[index1]!=s2[index2]){
            left = recursion(dp, s1, s2, index1, index2-1);
            right = recursion(dp, s1, s2, index1-1, index2);
        } 
        
        return dp[index1][index2] = max(left, right);
        
    
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return recursion(dp, text1, text2, text1.size()-1, text2.size()-1);
    }
};