class Solution {
  public:
//     string recursion(vector<vector<string>> &dp, string &s1, string &s2, int index1, int index2){
//         if(index1<0 || index2<0){
//             return "";
//         }
        
//         if(dp[index1][index2]!="") return dp[index1][index2];
//         string left = "";
//         string right = "";
        
       
//         if(s1[index1]!=s2[index2]){
//             left = recursion(dp, s1, s2, index1, index2-1);
//             right = recursion(dp, s1, s2, index1-1, index2);
//         } else {
//             return recursion(dp, s1, s2, index1-1, index2-1) + s1[index1];
//         } 
        
// if (left.size() > right.size()) {
//     return dp[index1][index2] = left;
// } else {
//     return dp[index1][index2] = right;
// }
    
        
    // }
    int lcs(string &s1, string &s2) {
        // vector<vector<string>> dp(s1.size(), vector<string>(s2.size(), ""));
        // string s = recursion(dp, s1, s2, s1.size()-1, s2.size()-1);
        // cout<<s;
        // return  1;
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
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[size1][size2];
    }
};
