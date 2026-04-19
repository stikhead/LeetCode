class Solution {
  public:
    bool isPal(string s){
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
    void backtrack(vector<vector<string>> &ans, vector<string> &op, string s, int index){
        if(s.size()==index){
            ans.push_back(op);
            return;
        }
        
        string temp = "";
        for(int i=index; i<s.size(); i++){
            temp.push_back(s[i]);
            if(isPal(temp)){
                op.push_back(temp);
                backtrack(ans, op, s, i+1);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans = {};
        vector<string> op = {};
        backtrack(ans, op, s, 0);
        return ans;
        
    }
};