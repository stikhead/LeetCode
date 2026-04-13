class Solution {
  public:
  
    void recursion(vector<string> &op, string input, string output){
        if(input.size()==0){
            op.push_back(output);
            return;
        }
        
        string output1 = output; //not taking
        string output2 = output; // taking

        output2.push_back(input[0]);
        input.erase(input.begin() + 0);
        
        recursion(op, input, output1);
        recursion(op, input, output2);
        
    }
    vector<string> powerSet(string s) {
        vector<string> op;
        string output = "";
        recursion(op, s, output);
        return op;
        
    }
};
