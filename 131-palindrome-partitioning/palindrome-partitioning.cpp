class Solution {
public:

    bool isPalindrome(string &s){
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void backtrack( vector<vector<string>> &ans, vector<string> op, string input, int index){
        if(index==input.size()){
            ans.push_back(op);
            return;
        }
        string opHold = "";
        for(int i=index; i<input.size(); i++){
            opHold.push_back(input[i]);
            if(isPalindrome(opHold)){
                op.push_back(opHold);
                backtrack(ans, op, input, i + 1);
                op.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans = {};
        vector<string> op = {};
        backtrack(ans, op, s, 0);
        return ans;
    }
};