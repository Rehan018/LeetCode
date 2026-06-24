class Solution {
public:
    static const int MOD = 1e9 + 7;

    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] +
                         A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp) {

            if (exp & 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);

            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        if (n == 1) return m;

        int sz = 2 * m;

        Matrix T(sz, vector<ll>(sz, 0));

        

        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                T[v][m + u] = 1;
            }

            for (int u = v + 1; u < m; u++) {
                T[m + v][u] = 1;
            }
        }

        vector<ll> base(sz, 0);

        for (int v = 0; v < m; v++) {

            base[v] = v;
            base[m + v] = m - 1 - v; 
        }

        if (n == 2) {

            ll ans = 0;

            for (ll x : base) {
                ans = (ans + x) % MOD;
            }

            return ans;
        }

        Matrix P = power(T, n - 2);

        vector<ll> finalState(sz, 0);

        for (int i = 0; i < sz; i++) {

            for (int j = 0; j < sz; j++) {

                finalState[i] =
                    (finalState[i] +
                     P[i][j] * base[j]) % MOD;
            }
        }

        ll ans = 0;

        for (ll x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};