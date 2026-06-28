function minFallingPathSum(matrix: number[][]): number {

    const n = matrix.length;

    for (let i = 1; i < n; i++) {

        for (let j = 0; j < n; j++) {

            let up = matrix[i - 1][j];

            let left = j > 0
                ? matrix[i - 1][j - 1]
                : Number.MAX_SAFE_INTEGER;

            let right = j < n - 1
                ? matrix[i - 1][j + 1]
                : Number.MAX_SAFE_INTEGER;

            matrix[i][j] += Math.min(up, left, right);
        }
    }

    let ans = Number.MAX_SAFE_INTEGER;

    for (let j = 0; j < n; j++) {
        ans = Math.min(ans, matrix[n - 1][j]);
    }

    return ans;
}