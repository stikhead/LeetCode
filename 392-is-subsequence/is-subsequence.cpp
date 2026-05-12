class Solution {
public:
    int recursion(vector<vector<int>> &dp, string &s, string &t, int index1, int index2){
        if(index1<0 || index2<0){
            return 0;
        }

        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1]==t[index2]){
            return dp[index1][index2] = 1 + recursion(dp, s, t, index1-1, index2-1);
        }

        int left = recursion(dp, s, t, index1-1, index2);
        int right = recursion(dp, s, t, index1, index2-1);
        return dp[index1][index2] = max(left, right);
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        int sol = recursion(dp, s, t, s.size()-1, t.size()-1);
      
        return (s.size() - sol) == 0 ? true : false;
    }
};