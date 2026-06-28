class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {

        int r = -1, c = -1;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                    break;
                }
            }
            if (r != -1) break;
        }

        int ans = 0;

        vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for (auto &[dr, dc] : dirs) {

            int nr = r + dr;
            int nc = c + dc;

            while (nr >= 0 && nr < 8 &&
                   nc >= 0 && nc < 8) {

                if (board[nr][nc] == 'B')
                    break;

                if (board[nr][nc] == 'p') {
                    ans++;
                    break;
                }

                nr += dr;
                nc += dc;
            }
        }

        return ans;
    }
};