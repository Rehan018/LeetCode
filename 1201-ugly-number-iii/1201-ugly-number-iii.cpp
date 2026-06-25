class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {

        ll ab = lcm(a, b);
        ll ac = lcm(a, c);
        ll bc = lcm(b, c);
        ll abc = lcm(ab, c);

        ll left = 1;
        ll right = 2e9;

        while (left < right) {

            ll mid = left + (right - left) / 2;

            ll cnt =
                mid / a +
                mid / b +
                mid / c -
                mid / ab -
                mid / ac -
                mid / bc +
                mid / abc;

            if (cnt >= n)
                right = mid;
            else
                left = mid + 1;
        }

        return (int)left;
    }
};