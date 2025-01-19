class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        int low = 0, high = s.size() - 1;
        
        while (low < high) {
            while (low < high && !isVowel(s[low])) {
                low++;
            }
            while (low < high && !isVowel(s[high])) {
                high--;
            }
            if (low < high) {
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }
        
        return s;
    }
};
