#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int n = d.size();
        vector<long long> arr(n + 1, 0);
        arr[0] = 0;

        for (int i = 0; i < n; i++) {
            arr[i + 1] = arr[i] + d[i];
        }

        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        int range = (upper - lower) - (maxVal - minVal) + 1;

        return max(0, range);
    }
};
