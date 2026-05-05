class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        if (ops.size() == 0)
            return m * n;
        int min1 = m;
        int min2 = n;
        for (int i = 0; i < ops.size(); i++) {

            min1 = min(min1, ops[i][0]);
            min2 = min(min2, ops[i][1]);
        }
        return min1 * min2;
    }
};