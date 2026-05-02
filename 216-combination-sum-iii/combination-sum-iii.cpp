class Solution {
public:
    void recursion(vector<vector<int>> &ans, vector<int> &subset, int &sum, int k, int n, int value){
        if(subset.size()==k && sum==n){
            ans.push_back(subset);
            return;
        }

        if(subset.size() > k){
            return;
        }

        for(int i=value; i<=9; i++){
            if(sum+i<=n){
                sum+=i;
                subset.push_back(i);
                recursion(ans, subset, sum, k, n, i + 1 );
                subset.pop_back();
                sum-=i;
            }
        }


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        int sum = 0;
        recursion(ans, subset, sum, k, n, 1);
        return ans;
    }
};