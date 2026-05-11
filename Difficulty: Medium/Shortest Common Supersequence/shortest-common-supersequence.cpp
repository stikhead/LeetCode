class Solution {
  public:
    // int recursion(vector<vector<int>> &dp, string &s1, string &s2, int index1, int index2){
    //     if(index1<0){
    //         return index2+1;
    //     }
    //     if(index2<0){
    //         return index1+1;
    //     }
    //     if(dp[index1][index2]!=-1) return dp[index1][index2];
    //     if(s1[index1]==s2[index2]){
    //         return dp[index1][index2] = 1 + recursion(dp, s1, s2, index1-1, index2-1);
    //     }
        
    //     int left = 1 + recursion(dp, s1, s2, index1-1, index2);
    //     int right = 1 + recursion(dp, s1, s2, index1, index2-1);
    //     return dp[index1][index2] = min(left, right);
    // }
    
    int recursion(vector<vector<int>> &dp, string &s1, string &s2, int index1, int index2){
        if(index1<0 || index2<0){
           return 0;
        }
        
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s1[index1]==s2[index2]){
            return dp[index1][index2] = 1 + recursion(dp, s1, s2, index1-1, index2-1);
        }
        
        int left = recursion(dp, s1, s2, index1-1, index2);
        int right = recursion(dp, s1, s2, index1, index2-1);
        return dp[index1][index2] = max(left, right);
    }
    int minSuperSeq(string &s1, string &s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        // return recursion(dp, s1, s2, s1.size()-1, s2.size()-1);
        //  we can literally count su[ersubsequence by adding both string length and then substracting common part of both string
        return s1.size() + s2.size() - recursion(dp, s1, s2, s1.size()-1, s2.size()-1); 
        
    }
};