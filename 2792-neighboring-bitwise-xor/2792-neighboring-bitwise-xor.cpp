class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int>m = {0};
        for(int i = 0;i < derived.size();i++){
            m.push_back(derived[i] ^ m[i]);
        }
        if(m[0] == m[m.size() - 1]) return true;
        m = {1};
        for(int i = 0;i < derived.size();i++){
            m.push_back(derived[i] ^ m[i]);
        }
        if(m[0] == m[m.size() - 1]) return true;
        return false;
    }
};