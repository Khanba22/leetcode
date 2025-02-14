class ProductOfNumbers {
public:
    vector<int> list;
    int prod = 1;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            list = {};
            prod = 1;
        } else {
            prod *= num;
            list.push_back(prod);
        }
    }

    int getProduct(int k) {
        int n = list.size();
        int t = list.back();
        if (n < k) return 0;
        if (n == k) return t;
        return t / list[n - k - 1];
    }
};