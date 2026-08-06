class Solution {
public:
    int digitProduct(int num) {
        if (num == 0)
            return 0;

        int product = 1;

        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        int current = n;

        while (true) {
            if (digitProduct(current) % t == 0)
                return current;

            current++;
        }
    }
};