class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> m;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && j != k && i != k && digits[i] != 0) {
                        int num = (100 * digits[i]) + (10 * digits[j]) + digits[k];
                        if (num % 2 == 0) {
                            m.insert(num);
                        }
                    }
                }
            }
        }
        vector<int> res;
        for (auto& i : m) {
            res.push_back(i);
        }
        sort(res.begin(),res.end());
        return res;
    }
};