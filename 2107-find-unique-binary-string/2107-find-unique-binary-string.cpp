class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int> seen;
        int start = 0;
        for (string s : nums) {
            seen[stoi(s, 0, 2)]++;
        }
        while (true) {
            if (!seen.count(start)) {
                return toBinaryString(start,nums[0].size());
            }
            start++;
        }
        return "";
    }

    string toBinaryString(int num, int length) {
        string result = "";
        while (num > 0) {
            result = (char)('0' + (num % 2)) + result;
            num /= 2;
        }
        while (result.size() < length) {
            result = '0' + result;
        }
        return result;
    }
};

