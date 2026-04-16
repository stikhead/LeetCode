class Solution {
  public:
  

    int recursion(vector<int> &arr, int k, int &index){
        if(arr.size()==1){
            return arr[0];
        }
        
        int indexation = (index + k)%arr.size();
        arr.erase(arr.begin()+indexation);
        recursion(arr, k, indexation);
        
    }
    int safePos(int n, int k) {
        vector<int> vec(n);
        iota(vec.begin(), vec.end(), 1);
        int i = 0;
        return recursion(vec, k-1, i);
    }
};
