class Solution {
public:
    int minLength(string s) {
        if(s.size() <= 1) return s.size();
        string stack = {s[0]};
        for(int i = 1;i < s.size();i++){
            if(!stack.empty() && ((stack.back() == 'A' && s[i] == 'B') || (stack.back() == 'C' && s[i] == 'D'))) stack.pop_back();
            else stack.push_back(s[i]);
        }
        return stack.size();
    }
};