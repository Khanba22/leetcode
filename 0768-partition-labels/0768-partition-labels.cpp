#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> P(26, -1);
        
        for (int i = 0; i < n; ++i) {
            P[s[i] - 'a'] = i;
        }
        
        vector<int> pLen;
        int start = 0, end = -1;
        
        for (int i = 0; i < n; ++i) {
            end = max(end, P[s[i] - 'a']);
            if (i == end) {
                pLen.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return pLen;
    }
};
