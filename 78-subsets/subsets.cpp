class Solution {
public:

    void recursion(vector<vector<int>>& op, vector<int> input, vector<int> output){
        if(input.size()==0){
            op.push_back(output);
            return;
        }

        vector<int> output1 = output;
        vector<int> output2 = output;
        output2.push_back(input[0]);
        swap(input.front(), input.back());
        input.pop_back();

        recursion(op, input, output1);
        recursion(op, input, output2);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> op = {};
        recursion(output, nums, op);
        return output;
    }
};