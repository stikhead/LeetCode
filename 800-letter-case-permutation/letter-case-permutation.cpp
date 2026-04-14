class Solution {
public:

    void recursion(vector<string> &op, int index, string &input, string &output){
        if(index==input.size()){
            op.push_back(output);
            return;
        }

        if(input[index]>=48 && input[index]<=57){
            output.push_back(input[index]);
            recursion(op, index + 1, input, output);
            output.pop_back();
        } else {
           output.push_back(toupper(input[index]));
           recursion(op, index + 1, input, output);
           output.pop_back(); 
           
           output.push_back(tolower(input[index]));
           recursion(op, index + 1, input, output);
           output.pop_back();
           
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> output = {};
        string op = "";
        recursion(output, 0, s, op);
        return output;
    }
};