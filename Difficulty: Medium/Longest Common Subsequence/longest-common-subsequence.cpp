class Solution {
  public:
    int recursion(vector<vector<int>> &dp, string &s1, string &s2, int index1, int index2){
        if(index1<0 || index2<0){
            return 0;
        }
        
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int left = 0;
        int right = 0;
        
       
        if(s1[index1]!=s2[index2]){
            left = recursion(dp, s1, s2, index1, index2-1);
            right = recursion(dp, s1, s2, index1-1, index2);
        } else {
            return 1 + recursion(dp, s1, s2, index1-1, index2-1);
        } 
        
        return dp[index1][index2] = max(left, right);
        
    
        
    }
    int lcs(string &s1, string &s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return recursion(dp, s1, s2, s1.size()-1, s2.size()-1);
        
    }
};
