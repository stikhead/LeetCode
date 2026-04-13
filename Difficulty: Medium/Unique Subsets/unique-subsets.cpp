class Solution {
  public:
    // Function to find all possible unique subsets.
    void recursion(vector<vector<int>> &op, int index, vector<int> &input, vector<int> output, set<vector<int>> &s){
        if(index==input.size()){
            sort(output.begin(), output.end());
            if(s.find(output)==s.end()){
                s.insert(output);
                op.push_back(output);
            }
            return;
        }
        
    
        
        recursion(op, index + 1, input, output, s);
        output.push_back(input[index]);
        recursion(op, index+1, input, output, s);
        
        output.pop_back();
        
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n) {
        vector<vector<int>> output;
        vector<int> op = {};
        set<vector<int>> s;
        
        recursion(output, 0, arr, op, s);
        sort(output.begin(), output.end());
        return output;
        
        
    }
};