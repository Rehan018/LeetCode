/**
 * @param {string[]} grid
 * @return {number}
 */
var regionsBySlashes = function(grid) {

    const n = grid.length;
    const size = n * 3;

    const mat = Array.from(
        { length: size },
        () => Array(size).fill(0)
    );

    for (let i = 0; i < n; i++) {

        for (let j = 0; j < n; j++) {

            if (grid[i][j] === '/') {

                mat[i * 3][j * 3 + 2] = 1;
                mat[i * 3 + 1][j * 3 + 1] = 1;
                mat[i * 3 + 2][j * 3] = 1;

            } else if (grid[i][j] === '\\') {

                mat[i * 3][j * 3] = 1;
                mat[i * 3 + 1][j * 3 + 1] = 1;
                mat[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }

    const dfs = (r, c) => {

        if (
            r < 0 || r >= size ||
            c < 0 || c >= size ||
            mat[r][c] !== 0
        ) {
            return;
        }

        mat[r][c] = 2;

        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    };

    let regions = 0;

    for (let i = 0; i < size; i++) {

        for (let j = 0; j < size; j++) {

            if (mat[i][j] === 0) {
                regions++;
                dfs(i, j);
            }
        }
    }

    return regions;
};