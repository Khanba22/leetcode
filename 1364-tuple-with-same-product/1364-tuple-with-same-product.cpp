class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> prods;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int prod = nums[i] * nums[j];
                prods[prod]++;
            }
        }
        int count = 0;
        for (auto& i : prods) {
            if (i.second > 1) {
                count += (i.second * (i.second - 1)) * 4;
            }
        }
        return count;
    }
};