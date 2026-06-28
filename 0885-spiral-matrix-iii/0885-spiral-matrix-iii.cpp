class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols,
                                        int rStart, int cStart) {

        vector<vector<int>> ans;

        int total = rows * cols;

        vector<pair<int, int>> dir = {
            {0, 1},   
            {1, 0},   
            {0, -1},  
            {-1, 0}
        };

        int len = 1;
        int d = 0;

        int r = rStart;
        int c = cStart;

        if (r >= 0 && r < rows && c >= 0 && c < cols)
            ans.push_back({r, c});

        while (ans.size() < total) {

            for (int k = 0; k < 2; k++) {

                for (int step = 0; step < len; step++) {

                    r += dir[d].first;
                    c += dir[d].second;

                    if (r >= 0 && r < rows &&
                        c >= 0 && c < cols) {

                        ans.push_back({r, c});

                        if (ans.size() == total)
                            return ans;
                    }
                }

                d = (d + 1) % 4;
            }

            len++;
        }

        return ans;
    }
};