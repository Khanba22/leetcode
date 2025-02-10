class Solution {
public:
    string clearDigits(string s) {
        string res;
        for(int i = 0;i < s.size();i++){
            if('0' <= s[i] && s[i] <= '9'){
                res.pop_back();
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};