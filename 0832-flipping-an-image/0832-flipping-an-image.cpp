class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int m = image.size();
        int n = image[0].size();

        for (int i = 0; i < m; i++) {

            int l = 0, r = n - 1;

            while (l <= r) {

                if (l == r) {
                    image[i][l] ^= 1;
                } else {
                    int left = image[i][l];
                    int right = image[i][r];

                    image[i][l] = right ^ 1;
                    image[i][r] = left ^ 1;
                }

                l++;
                r--;
            }
        }

        return image;
    }
};