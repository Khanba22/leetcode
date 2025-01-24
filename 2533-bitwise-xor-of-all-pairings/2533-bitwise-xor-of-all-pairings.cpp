class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int res2 = 0;
        if (nums2.size() & 1) {
            for (int i = 0; i < nums1.size(); i++) {
                res ^= nums1[i];
            }
        }
        if (nums1.size() & 1) {
            for (int i = 0; i < nums2.size(); i++) {
                res2 ^= nums2[i];
            }
        }
        return res ^ res2;
    }
};