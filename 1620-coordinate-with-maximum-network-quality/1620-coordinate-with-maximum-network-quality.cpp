class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {

        int bestX = 0;
        int bestY = 0;
        int bestQuality = -1;

        int r2 = radius * radius;

        for (int x = 0; x <= 50; ++x) {

            for (int y = 0; y <= 50; ++y) {

                int quality = 0;

                for (auto &t : towers) {

                    int dx = x - t[0];
                    int dy = y - t[1];

                    int d2 = dx * dx + dy * dy;

                    if (d2 > r2)
                        continue;

                    quality += (int)(t[2] / (1.0 + sqrt(d2)));
                }

                if (quality > bestQuality) {
                    bestQuality = quality;
                    bestX = x;
                    bestY = y;
                }
            }
        }

        return {bestX, bestY};
    }
};