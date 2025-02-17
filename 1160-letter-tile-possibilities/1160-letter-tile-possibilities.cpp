class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char &c : tiles) freq[c]++;

        return backtrack(freq);
    }

private:
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        for (auto& [ch, val] : freq) {
            if (val == 0) continue;

            freq[ch]--;
            count += 1 + backtrack(freq); 
            freq[ch]++;
        }
        return count;
    }
};
