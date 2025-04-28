class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(char &c:s){
            freq[c]++;
        }
        int longestOdd = 0;
        int res = 0;
        for(auto [a,b]:freq){
            if(b % 2 ==0){
                res+=b;
            }else{
                res+=b - 1;
            }
        }
        return res == s.size()?res:res+1;
    }
};