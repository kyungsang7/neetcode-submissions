class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        stk.push({0, heights[0]});

        int ans = heights[0];
        for(int i = 1; i < heights.size(); i++){
            if (stk.top().second > heights[i]){
                int idx = i;
                while (!stk.empty() && stk.top().second > heights[i]){
                idx = stk.top().first;
                ans = max(ans, (i - idx) * stk.top().second);
                stk.pop();
                }
                stk.push({idx, heights[i]});
            }
            else{
                ans = max(ans, heights[i]);
                stk.push({i, heights[i]});
            }
        }

        int n = heights.size();
        while (!stk.empty()){
            ans = max((n-stk.top().first) * stk.top().second, ans);
            stk.pop();
        }

        return ans;
    }
};

