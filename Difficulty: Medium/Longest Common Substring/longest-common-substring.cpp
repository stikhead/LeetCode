class Solution {
  public:
    int recursion(vector<vector<int>> &dp, string &s1, string &s2, int index1, int index2, int &streak){
        
        if(index1<0 || index2<0){
            return 0;
        }
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int curr = 0;
        if(s1[index1]==s2[index2]){
            curr = 1 + recursion(dp, s1, s2, index1-1, index2-1, streak);
            streak = max(curr, streak);
        }
        
         recursion(dp, s1, s2, index1, index2-1, streak);
         recursion(dp, s1, s2, index1-1, index2, streak);
         return dp[index1][index2] = curr;
            
        
    }
    int longCommSubstr(string& s1, string& s2) {
         int s = 0;
         vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
         recursion(dp, s1, s2, s1.size()-1, s2.size()-1, s);
        return s;
    }
};