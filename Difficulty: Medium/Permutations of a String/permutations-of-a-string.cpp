class Solution {
  public:
//   void recursion(vector<string> &output, string input, string op){
//       if(input.size()==0){
//           output.push_back(op);
//           return;
//       }
//       unordered_set<char> mp;
//       for(int i=0; i<input.size(); i++){
//             if(mp.find(input[i])==mp.end()){
//                 mp.insert(input[i]);
//                 string newInput = input.substr(0, i) + input.substr(i+1, input.size());
//                 string newOutput = op + input[i];
//                 recursion(output, newInput, newOutput);
//             }
//       }
//   }

    void backtracking(vector<string> &output,string &input, int index){
        if(index==input.size()-1){
            output.push_back(input);
            return; 
        }
        
        unordered_set<char> mp;
        for(int i=index; i<input.size(); i++){
            if(mp.find(input[i])==mp.end()){
                mp.insert(input[i]);
                swap(input[i], input[index]);
                backtracking(output, input, index+1);
                swap(input[i], input[index]);
            }
        }
    }
    vector<string> findPermutation(string &s) {
        vector<string> output = {};
        backtracking(output, s, 0);
        return output;
    }
};
