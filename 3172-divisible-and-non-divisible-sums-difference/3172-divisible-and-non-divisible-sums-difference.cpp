class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int div = n / m;
        return totalSum - m * (div * (div + 1));
    }
};
