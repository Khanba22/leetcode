class Solution:
    def frequencySort(self, s: str) -> str:
        freq = dict()
        for char in s:
            freq[char] = freq.get(char, 0) + 1

        sorted_freq = sorted(freq.items(), key=lambda item: item[1], reverse=True)
        result = ''.join(char * freq for char, freq in sorted_freq)
        
        return result
