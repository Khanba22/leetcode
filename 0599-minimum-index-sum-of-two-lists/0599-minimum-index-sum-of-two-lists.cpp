class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        map<string, int> m;
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }
        int minIndex = INT_MAX;
        vector<string> res;
        for (int i = 0; i < list2.size(); i++) {
            if (m.find(list2[i]) != m.end()) {
                string c = list2[i];
                int sum = i + m[c];
                if (sum == minIndex) {
                    res.push_back(c);
                } else if (sum < minIndex) {
                    minIndex = sum;
                    res = {};
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};