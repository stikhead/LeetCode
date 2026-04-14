class Solution {
  public:

    void recursion(vector<string> &op, int index, string &input, string &output){
        if(index==input.size()){
            op.push_back(output);
            return;
        }
        
        if(index==0){
            output.push_back(input[index]);
            recursion(op, index+1, input, output);
        } else {
        
        output.push_back(' ');
        output.push_back(input[index]);
        recursion(op, index+1, input, output);
        output.pop_back();
        output.pop_back();
        output.push_back(input[index]);
        recursion(op, index+1, input, output);
                output.pop_back();
        return;
        }        
    }
    vector<string> permutation(string s) {
        vector<string> output = {};
        string op = "";
        recursion(output, 0, s, op);
        return output;
    }
};