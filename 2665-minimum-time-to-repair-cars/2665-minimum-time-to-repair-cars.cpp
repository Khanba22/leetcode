class Solution {
public:
    bool canRepair(vector<int>& ranks, int cars, long long time) {
        long long carsDone = 0;
        for (int i : ranks) {
            carsDone += sqrt(time / i);
            if (carsDone >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0;
        long long high = (long long) *min_element(ranks.begin(), ranks.end()) * (long long)cars * (long long)cars;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canRepair(ranks, cars, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};