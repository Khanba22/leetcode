class Solution {
public:
    bool helper(int &n, int &k, string &curr, int index, string &res) {
        if (index == n) {
            k--;
            if (k == 0) {
                res = curr;
                return true; 
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) continue; 
            curr.push_back(ch);
            if (helper(n, k, curr, index + 1, res)) return true; 
            curr.pop_back(); 
        }
        return false;
    }

    string getHappyString(int n, int k) {
        string res = "";
        string curr = "";
        helper(n, k, curr, 0, res);
        return res;
    }
};
