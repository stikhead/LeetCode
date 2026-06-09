class Solution {
public:
    pair<int, int> getCoords(int square, int n) {
        int s = square - 1;
        int row_from_bottom = s / n;
        int r = (n - 1) - row_from_bottom;
        int c = s % n;
        if (row_from_bottom % 2 != 0)
            c = (n - 1) - c;
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        vector<int> dist(target+1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty()) {
            int square = q.front();
            q.pop();
            if (square == target)
                return dist[square];
            for (int i = 1; i <= 6; i++) {
                int next_square = square + i;

                if (next_square > target)
                    break;

                auto [r, c] = getCoords(next_square, n);

                if (board[r][c] != -1) {
                    next_square = board[r][c];
                }

                if (dist[next_square] == -1) {
                    q.push(next_square);
                    dist[next_square] = dist[square] + 1;
                }
            }
        }
        return -1;
    }
};