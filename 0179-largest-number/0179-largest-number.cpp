class Solution {
public:
    static bool customCompare(string& a, string& b) {
        return a + b > b + a; 
    }

    string largestNumber(vector<int>& nums) {
        vector<string> newNums;
        for (int num : nums) {
            newNums.push_back(to_string(num));
        }

        sort(newNums.begin(), newNums.end(), customCompare);

        if (newNums[0] == "0") return "0";

        string res = "";
        for (string& num : newNums) {
            res += num;
        }

        return res;
    }
};
