class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int count = 0;
        vector<char>t(2);
        for(int i = 0;i < s1.size();i++){
            if(s1[i] != s2[i]){
                count++;
                if(count > 2 || (count == 2 && (t[0] != s2[i] || t[1] != s1[i]))){
                    return false;
                }
                t = {s1[i],s2[i]};
            }
        }
        return count == 0 || count == 2;
    }
};