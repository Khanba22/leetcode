class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1, pivotCount = 0;

        for (int num : nums) {
            if (num < pivot) result[left++] = num;
            else if (num == pivot) pivotCount++;
        }

        for (int i = 0; i < pivotCount; i++) result[left++] = pivot;

        for (int num : nums) {
            if (num > pivot) result[left++] = num;
        }

        return result;
    }
};
