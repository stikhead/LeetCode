class Solution {
public:
    bool IsPalindrome(string &s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int recursion(vector<int> &dp, string &s, int index){
        if(index<=0) return 0;
        
        if(dp[index]!=-1) return dp[index];
        if(IsPalindrome(s, 0, index)) return dp[index] = 0;
        int ans = INT_MAX;
        for(int k=1; k<=index; k++){
            if(IsPalindrome(s, k, index)){
                int temp = recursion(dp, s, k-1) + 1;
                ans = min(temp,ans);
            }
        }
    
        return dp[index] = ans;
    }
    
    int minCut(string s) {
        vector<int> dp(s.size()+1, -1);
      
        return recursion(dp, s, s.size()-1);
    }
};