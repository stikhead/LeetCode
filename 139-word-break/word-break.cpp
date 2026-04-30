class Solution {
public:
    bool recursion(string& construct, string& s, vector<string>& dict, int index, unordered_map<string, bool>& memo) {
        string state = to_string(index) + "|" + construct;

        if (memo.count(state)) {
            return memo[state];
        }
        
        if (index == s.size() - 1) {
            for (int i = 0; i < dict.size(); i++) {
                if (construct == dict[i]) {
                    return memo[state] = true;;
                }
            }
            return memo[state] = false;
        }

        for (int i = 0; i < dict.size(); i++) {
            if (construct == dict[i]) {
                string temp = "";
                index++;
                temp.push_back(s[index]);
                bool flag = recursion(temp, s, dict, index, memo);
                temp.pop_back();
                index--;
                if (flag) {
                    return memo[state] = true;
                } 
            }
        }
        index++;
        construct.push_back(s[index]);
        bool f = recursion(construct, s, dict, index, memo);
        construct.pop_back();
        index--;
        return memo[state] = f;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int mx = 0;
        unordered_map<char, int> charCounts;
        for (const std::string& word : wordDict) {
            for (char c : word) {
                charCounts[c]++;
            }

            mx = max<int>(mx, word.size());
        }

        unordered_map<char, int> charCountsFromString;
        for (char c : s) {
            charCountsFromString[c]++;
        }

        if (charCountsFromString.size() > charCounts.size()) {
            return false;
        }

        unordered_map<string, bool> memo;

        string construct = "";
        int size = 0;
        int i = 0;
        while (i < s.size() && i < mx) {
            construct.push_back(s[i]);
            bool ans = recursion(construct, s, wordDict, i, memo);
            if (ans) {
                return true;
            }
            i++;
        }
        return false;
    }
};