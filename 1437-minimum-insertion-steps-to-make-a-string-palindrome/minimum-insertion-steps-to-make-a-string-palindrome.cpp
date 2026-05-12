class Solution {
public:
    int recursion(vector<vector<int>> &dp, string &s, int index1, int index2){
        
        if(index2>index1) return 0; 
        if(index1==index2) return 1;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s[index1]==s[index2]){
            return dp[index1][index2] = 2 + recursion(dp, s, index1-1,index2+1);
        }
        int left = recursion(dp, s, index1-1, index2);
        int right = recursion(dp, s, index1, index2+1);
        return dp[index1][index2] = max(left, right);
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
        // string rev = s;
        // reverse(s.begin(), s.end());
        return s.size() - recursion(dp, s, s.size()-1, 0);
    }
};