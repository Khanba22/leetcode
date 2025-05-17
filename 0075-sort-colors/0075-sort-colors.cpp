class Solution {
public:
    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> arr(high - low + 1);
        int k = 0;
        int i = low;  
        int j = mid + 1; 
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                arr[k++] = nums[i++];
            } else {
                arr[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            arr[k++] = nums[i++];
        }
        while (j <= high) {
            arr[k++] = nums[j++];
        }
        for (int i = 0; i < arr.size(); ++i) {
            nums[low + i] = arr[i];
        }
    }
};
