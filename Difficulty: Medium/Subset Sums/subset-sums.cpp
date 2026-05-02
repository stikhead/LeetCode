class Solution {
  public:
    void recursion(vector<int> &ans, vector<int> &arr, int &sum, int index){
        if(index==arr.size()){
            ans.push_back(sum);
            return;
        }
        
        sum+=arr[index];
        recursion(ans, arr ,sum, index+1);
        sum-=arr[index];
        recursion(ans, arr, sum, index+1);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sum;
        // vector<int> subset;
        int s = 0;
        recursion(sum, arr, s, 0);
        return sum;
    }
};