// User function template for C++
class Solution {
  public:
  
    void recursion(vector<string> &output, int n, int one, int zero, string &op){
        if(zero+one==n && one>=zero){
            output.push_back(op);
            return;
        }    
        
        if(one < n){
            op.push_back('1');
            recursion(output, n, one + 1, zero, op);
            op.pop_back();
        }
        
        if(zero < one){
            op.push_back('0');
            recursion(output, n, one, zero + 1, op);
            op.pop_back();
        }
    }
    
    vector<string> NBitBinary(int n) {
        vector<string> output = {};
        string op = "";
        recursion(output, n, 0, 0, op);
        return output;
    }
};