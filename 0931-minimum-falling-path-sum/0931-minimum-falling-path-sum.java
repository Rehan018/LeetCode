class Solution {
    public int minFallingPathSum(int[][] matrix) {

        int n = matrix.length;

        for (int i = 1; i < n; i++) {

            for (int j = 0; j < n; j++) {

                int up = matrix[i - 1][j];

                int left = (j > 0)
                        ? matrix[i - 1][j - 1]
                        : Integer.MAX_VALUE;

                int right = (j < n - 1)
                        ? matrix[i - 1][j + 1]
                        : Integer.MAX_VALUE;

                matrix[i][j] += Math.min(up, Math.min(left, right));
            }
        }

        int ans = Integer.MAX_VALUE;

        for (int val : matrix[n - 1]) {
            ans = Math.min(ans, val);
        }

        return ans;
    }
}