class Solution {
public:
    void backtrack(string& num, int target, vector<string>& ans, string path, int index, long eval, long prev) {
       
        if (index == num.length()) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            if (i != index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long currNum = stol(currStr);

            if (index == 0) {
                backtrack(num, target, ans, path + currStr, i + 1, currNum, currNum);
            } else {
                backtrack(num, target, ans, path + "+" + currStr, i + 1, eval + currNum, currNum);
                
                backtrack(num, target, ans, path + "-" + currStr, i + 1, eval - currNum, -currNum);
                
                backtrack(num, target, ans, path + "*" + currStr, i + 1, eval - prev + (prev * currNum), prev * currNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrack(num, target, ans, "", 0, 0, 0);
        return ans;
    }
};