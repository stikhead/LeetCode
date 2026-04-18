// User function Template for C++
class Solution {
  public:
    
    void backtracking(vector<int> &output, int n, int &input){
        if(n==0){
            output.push_back(input);
            return;
        }
        
        for(int i=1; i<=9; i++){
            if(i>input%10){
                input = (input*10)+i;
                backtracking(output, n-1, input);
                input = input/10;
            }
        }
    }
    vector<int> increasingNumbers(int n) {
        vector<int> output;
        int op = 0;
        if(n==1){
            for(int i=0; i<=9; i++){
                output.push_back(i);
            }
        } else {
            backtracking(output, n, op);
        }
        return output;
    }
};