class Solution {
  public:
    // int recursion(vector<vector<int>> &dp, string &s1, string &s2, int index1, int index2, int &streak){
        
    //     if(index1<0 || index2<0){
    //         return 0;
    //     }
    //     if(dp[index1][index2]!=-1) return dp[index1][index2];
    //     int curr = 0;
    //     if(s1[index1]==s2[index2]){
    //         curr = 1 + recursion(dp, s1, s2, index1-1, index2-1, streak);
    //         streak = max(curr, streak);
    //     }
        
    //      recursion(dp, s1, s2, index1, index2-1, streak);
    //      recursion(dp, s1, s2, index1-1, index2, streak);
    //      return dp[index1][index2] = curr;
            
        
    // }
    int longCommSubstr(string& s1, string& s2) {
        //  int s = 0;
        //  vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        //  recursion(dp, s1, s2, s1.size()-1, s2.size()-1, s);
        // return s;
        int res = 0;
        int size1 = s1.size();
        int size2 = s2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, -1));
        for(int i=0; i<=size1; i++){
            dp[i][0] = 0;
        }
        for(int i=0; i<=size2; i++){
            dp[0][i] = 0;
        }
        
        for(int i=1; i<=size1; i++){
            for(int j=1; j<=size2; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
                
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
        
    }
};