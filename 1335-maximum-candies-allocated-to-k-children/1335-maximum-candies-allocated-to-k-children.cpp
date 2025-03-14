class Solution {
public:
    bool isSufficient(vector<int>& candies, long long k, int amount) {
        if (amount == 0) return false;
        long long count = 0;
        for (int &c : candies) {
            count += c / amount;
            if (count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = 0, res = 0;
        for(int &i:candies){
            high = max(high,i);    
        }
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
