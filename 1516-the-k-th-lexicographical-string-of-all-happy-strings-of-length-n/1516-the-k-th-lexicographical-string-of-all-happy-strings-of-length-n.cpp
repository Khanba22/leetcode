class Solution {
public:
    bool helper(int &n, int &k, string &curr, int &index, string &res, int &count) {
        if (index == n) {
            count++;
            if (count == k) {
                res = curr;
                return true; 
            }
            return false;
        }
        index++;
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) continue; 
            curr.push_back(ch);
            if (helper(n, k, curr, index, res, count)) return true; 
            curr.pop_back(); 
        }
        index--;
        return false;
    }

    string getHappyString(int n, int k) {
        int count = 0;
        string res = "";
        string curr = "";
        int index = 0;
        helper(n, k, curr, index, res, count);
        return res;
    }
};
