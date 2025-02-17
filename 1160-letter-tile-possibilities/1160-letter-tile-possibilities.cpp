#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26);
        for (char &c : tiles)
            freq[c - 65]++;

        return backtrack(freq, tiles.size());
    }

    int backtrack(vector<int>& freq, int remaining) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                freq[i]--;
                count += 1 + backtrack(freq, remaining - 1);
                freq[i]++;
            }
        }
        return count;
    }
};
