

class Solution {
  public:
    void backtracking(string &ans, string &input, int k, int index){
            ans = max(ans, input);
        if(k==0 || index==input.size()){
            return;
        }
        char mx = input[index];
        for(int i=index+1; i<input.size(); i++){
            mx = max(input[i], mx);
        }
        
        if(mx==input[index]){
             backtracking(ans, input, k, index+1);
        }
        for(int i=index+1; i<input.size(); i++){
            if(input[i]==mx){
                swap(input[i], input[index]);
                backtracking(ans, input, k-1, index+1);
                swap(input[i], input[index]);
            }
        }
    }
    string findMaximumNum(string& s, int k) {
        string ans = "";
        backtracking(ans, s, k, 0);
        return ans;
    }
};