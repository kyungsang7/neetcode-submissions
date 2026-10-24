class MinStack {
private:
    stack<long long> stk;
    long long minnum;

public:
    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            minnum = val;
            stk.push(0);
        } else {
            stk.push((long long)val - minnum);
            if (val < minnum) {
                minnum = val;
            }
        }
    }

    void pop() {
        long long tp = stk.top();
        stk.pop();

        if (tp < 0) {
            minnum -= tp;
        }
    }

    int top() {
        long long tp = stk.top();
        return (tp > 0) ? (int)(tp + minnum) : (int)minnum;
    }

    int getMin() {
        return (int)minnum;
    }
};
