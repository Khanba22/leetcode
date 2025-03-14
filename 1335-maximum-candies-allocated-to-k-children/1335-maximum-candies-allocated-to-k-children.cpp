class Solution {
public:
    bool isSufficient(vector<int>& candies, long long k, int amount) {
        if (amount == 0) return false;
        long long count = 0;
        for (int c : candies) {
            count += c / amount;
            if (count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (sum < k) return 0;

        int low = 1, high = sum / k, res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isSufficient(candies, k, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};
