class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> distinctNumbers;
        for (int n : nums) {
            distinctNumbers.insert(n);
            if (distinctNumbers.size() > 3) {
                distinctNumbers.erase(distinctNumbers.begin()); 
            }
        }

        if (distinctNumbers.size() < 3) {
            return *distinctNumbers.rbegin();
        }

        return *distinctNumbers.begin();
    }
};
