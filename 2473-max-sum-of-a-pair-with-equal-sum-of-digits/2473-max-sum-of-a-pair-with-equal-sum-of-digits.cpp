class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> sumMap; 
        int maxSum = -1;

        for (int num : nums) {
            int s = getDigitSum(num);

            auto& [first, second] = sumMap[s]; 

            if (num >= first) {
                second = first;
                first = num;
            } else if (num > second) {
                second = num;
            }
        }

        for (const auto& [key, value] : sumMap) {
            if (value.second != 0) {
                maxSum = max(maxSum, value.first + value.second);
            }
        }

        return maxSum;
    }
};
