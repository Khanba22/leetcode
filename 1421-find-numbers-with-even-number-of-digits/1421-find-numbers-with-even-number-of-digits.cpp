class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int countDigits = 1;
            while (nums[i] >= 10) {
                nums[i] = nums[i] / 10;
                countDigits++;
            }
            if (countDigits % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};