class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

        int rounds = minutesToTest / minutesToDie;

        int states = rounds + 1;

        int pigs = 0;
        long long capacity = 1;

        while (capacity < buckets) {
            capacity *= states;
            pigs++;
        }

        return pigs;
    }
};