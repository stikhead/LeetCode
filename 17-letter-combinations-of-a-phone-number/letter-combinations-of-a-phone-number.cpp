class Solution {
public:
    void recursion(vector<string> &ans, vector<string> &pad, string &s, string &digits, int index){
        
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = pad[digit];

        for(int i=0; i<letters.size(); i++){

            s.push_back(letters[i]);
            recursion(ans, pad, s, digits, index+1);
            s.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s = "";
        vector<string> pad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        recursion(ans, pad, s, digits, 0);
        return ans;
    }
};