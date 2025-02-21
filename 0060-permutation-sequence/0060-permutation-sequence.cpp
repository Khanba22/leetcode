class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            if (i < n) fact *= i;
        }
        
        k--;
        string res = "";

        for (int i = 0; i < n; i++) {
            int index = k / fact;
            res += to_string(numbers[index]);  
            numbers.erase(numbers.begin() + index);
            
            if (i < n - 1) {
                k %= fact;
                fact /= (n - 1 - i);
            }
        }
        
        return res;
    }
};
