#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMakeZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < k; i++) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }

        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diff[i];
            if (curr < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
        if (!canMakeZero(nums, queries, m)) return -1;

        int left = 1, right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeZero(nums, queries, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
