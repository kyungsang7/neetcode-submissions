class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        vector<int> ans(temperatures.size(), 0);
        int idx = temperatures.size() - 1;
        while (idx >= 0){
            int res = 0;
            int rec = temperatures[idx];
            while (!stk.empty()){
                if (stk.top().first > rec){
                    ans[idx] = stk.top().second - idx;
                    break;
                }
                else{
                    stk.pop();
                }
            }
            stk.push({temperatures[idx], idx});
            idx--;
        }
        return ans;
    }
};
