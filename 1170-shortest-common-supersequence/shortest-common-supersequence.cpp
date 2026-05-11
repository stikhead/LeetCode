class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int size1 = str1.size();
        int size2 = str2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, -1));
        for (int i = 0; i <= size1; i++) {
            dp[i][0] = i;
        }

        for (int i = 0; i <= size2; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1]);
                }
            }
        }
        string s = "";
        while (size1 > 0 && size2 > 0) {
            if (str1[size1 - 1] == str2[size2 - 1]) {
                s.push_back(str1[size1 - 1]);
                size1--;
                size2--;
            } else {
                if (dp[size1 - 1][size2] < dp[size1][size2 - 1]) {
                    s.push_back(str1[size1 - 1]);
                    size1--;
                } else {

                    s.push_back(str2[size2 - 1]);
                    size2--;
                }
            }
        }
        while (size1 > 0) {
            s.push_back(str1[size1 - 1]);
            size1--;
        }
        while (size2 > 0) {
            s.push_back(str2[size2 - 1]);
            size2--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};