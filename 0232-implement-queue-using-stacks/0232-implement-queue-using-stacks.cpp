class MyQueue {
public:
    vector<int> s1, s2;
    
    MyQueue() {}

    void push(int x) {
        s1.push_back(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push_back(s1.back());
                s1.pop_back();
            }
        }
        int val = s2.back();
        s2.pop_back();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push_back(s1.back());
                s1.pop_back();
            }
        }
        return s2.back();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
