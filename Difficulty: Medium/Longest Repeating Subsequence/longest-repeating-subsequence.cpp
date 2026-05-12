    // static int call = 0;
class Solution {
  public:
    int recursion(vector<vector<int>> &dp, string &s, int index1, int index2){
        if(index1<0 || index2<0) return 0;
        
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        // cout<<call++;
        if(s[index1]==s[index2] && index1!=index2){
            return dp[index1][index2] = 1 + recursion(dp, s, index1-1, index2-1);
        } 
        
        int left = recursion(dp, s, index1-1, index2);
        int right = recursion(dp, s, index1, index2-1);
        
        return dp[index1][index2] = max(left, right);
    }
    
    
    int LongestRepeatingSubsequence(string &s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return recursion(dp, s, s.size()-1, s.size()-1);
        
        for(int i=0; i<=s.size(); i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        for(int i = 1; i<=s.size(); i++){
            for(int j=1; j<=s.size(); j++){
                if(s[i]==s[j] && i!=j){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[s.size()][s.size()];
        
    }
};