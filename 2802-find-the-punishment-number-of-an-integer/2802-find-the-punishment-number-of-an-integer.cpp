class Solution {
public:
    bool checkPartition(string &s, int index, int sum, int target) {
        if (index == s.size()) {
            return sum == target;
        }
        
        int num = 0;
        for (int i = index; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0'); 
            if (checkPartition(s, i + 1, sum + num, target)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i*i);
            if (checkPartition(s, 0, 0, i)) {
                sum += i * i;
            }
        }
        return sum;
    }
};
