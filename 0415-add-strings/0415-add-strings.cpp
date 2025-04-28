class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size() - 1;
        int m = num2.size() - 1;
        int carry = 0;
        string res = "";
        
        while (n >= 0 || m >= 0 || carry) {
            int sum = carry;
            if (n >= 0) sum += num1[n--] - '0';
            if (m >= 0) sum += num2[m--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
