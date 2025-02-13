class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        for (int &num : nums) {
                heap.push(num);
        }
        int res = 0;
        while (!heap.empty() && heap.top() < k) {
            if (heap.size() < 2) break;
            long long x = heap.top(); 
            heap.pop();
            long long y = heap.top(); 
            heap.pop();
            long long newVal = min(x, y) * 2 + max(x, y);
            heap.push(newVal);
            res++;
        }
        return res;
    }
};
