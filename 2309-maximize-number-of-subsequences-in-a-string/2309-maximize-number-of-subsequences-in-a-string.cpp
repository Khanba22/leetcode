class Solution {
public:
    long long maximumSubsequenceCount(string text, string p) {
        long long count = 0, p0_count = 0;
        
        for (char ch : text) {
            if (ch == p[1]) {
                count += p0_count;
            }
            if (ch == p[0]) {
                p0_count++;
            }
        }
        
        long long add_p0 = count + count_if(text.begin(), text.end(), [&](char c){ return c == p[1]; });
        long long add_p1 = count + count_if(text.begin(), text.end(), [&](char c){ return c == p[0]; });
        
        return max(add_p0, add_p1);
    }
};
