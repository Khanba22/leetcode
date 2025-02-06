class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        map<int, int> prods;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                count += 8*(prods[nums[i] * nums[j]]++);
            }
        }
        return count;
    }
};