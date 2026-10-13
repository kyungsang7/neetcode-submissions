
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        priority_queue<int, vector<int>, greater<int>> heap;

        for (int a : nums) {
            heap.push(a);
        }

        int ans = 1;
        int res = 1;
        int prev = heap.top();
        heap.pop();

        while (!heap.empty()) {
            int n = heap.top();
            heap.pop();

            if (n == prev) {
                continue;
            }

            if (n == prev + 1) {
                res++;
            } else {
                ans = max(ans, res);
                res = 1;
            }

            prev = n;
        }

        return max(ans, res);
    }
};