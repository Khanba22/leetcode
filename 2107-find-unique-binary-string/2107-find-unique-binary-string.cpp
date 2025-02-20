class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int> seen;
        int n = nums[0].size();
        string endstr(n, '1');
        int start = 0;
        int end = stoi(endstr, 0, 2);
        for (string s : nums) {
            seen[stoi(s, 0, 2)]++;
        }
        while (start <= end) {
            if (!seen.count(start)) {
                return toBinaryString(start, n);
            }
            start++;
        }
        return toBinaryString(start, n);
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

