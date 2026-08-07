class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        } while (slow != fast);

        return slow == 1;
    }
};