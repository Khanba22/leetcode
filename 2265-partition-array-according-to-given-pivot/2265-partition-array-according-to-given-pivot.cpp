class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smaller;
        vector<int>larger;
        int pivotCount = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] < pivot){
                smaller.push_back(nums[i]);
            }else if(nums[i] > pivot){
                larger.push_back(nums[i]);
            }else{
                pivotCount++;
            }
        }
        for(int i = 0;i < pivotCount;i++){
            smaller.push_back(pivot);
        }
        for(int i = 0;i < larger.size();i++){
            smaller.push_back(larger[i]);
        }
        return smaller;
    }
};