// User function Template for C++

class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &price, int length, int index){
        // cout<<index<<" "<<length<<", ";
        if(length==0){
            return 0;
        }
        if(index<1){
            return 0;
        }
        
        if(dp[index][length]!=-1) return dp[index][length];
        int left = 0;
        if(length-index>=0){
            left = price[index-1] + recursion(dp, price, length-index, index);
        }
        int right = recursion(dp, price, length, index-1);
        return dp[index][length] = max(left, right);
    }
    int cutRod(vector<int> &price) {
        // return price[0];
        vector<vector<int>> dp(price.size()+1, vector<int>(price.size()+1, -1));
        return recursion(dp, price, price.size(), price.size());
        
    }
};