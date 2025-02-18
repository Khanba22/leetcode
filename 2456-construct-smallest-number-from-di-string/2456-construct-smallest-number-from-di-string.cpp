#include <string>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        unsigned char n = pattern.size();
        string result;
        char stack[11];
        uint8_t index = 0; 

        for (uint8_t i = 0; i <= n; i++) {
            stack[index++] = '1' + i;
            
            if (i == n || pattern[i] == 'I') {
                while (index > 0) {
                    result.push_back(stack[--index]);
                }
            }
        }

        return result;
    }
};
