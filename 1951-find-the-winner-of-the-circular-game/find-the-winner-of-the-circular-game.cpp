class Solution {
public:

    void recursion(vector<int> &arr, int k, int &index, int &ans){
        if(arr.size()==1){
            ans = arr[0];
            return;
        }
        
        int indexation = (index + k)%arr.size();
        arr.erase(arr.begin()+indexation);
        recursion(arr, k, indexation, ans);
       
    }
    int findTheWinner(int n, int k) {
        vector<int> vec(n);
        iota(vec.begin(), vec.end(), 1);
        int i = 0;
        int ans = 0;
        recursion(vec, k-1, i, ans);
        return ans;
    }
   
};