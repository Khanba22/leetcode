class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1000000007;
        int oddCount = 0, evenCount = 1;
        long long sum = 0, result = 0;

        for (int i = 0;i < arr.size();i++) {
            int num = arr[i];
            sum += num;
            if (sum % 2 == 0) {
                result = (result + oddCount) % MOD;
                evenCount++;
            } else {
                result = (result + evenCount) % MOD;
                oddCount++;
            }
        }

        return result;
    }
};
