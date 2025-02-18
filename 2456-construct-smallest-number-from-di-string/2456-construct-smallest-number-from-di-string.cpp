class Solution {
public:
    string smallestNumber(string pattern) {
        short n = pattern.length();
        string result = "";
        short stack[n + 1];
        short index = 0;
        for (short i = 0; i <= n; i++) {
            stack[index++] = i + 1;

            if (i == n || pattern[i] == 'I') {
                while (index > 0) {
                    result.push_back(stack[--index] + '0');
                }
            }
        }

        return result;
    }
};