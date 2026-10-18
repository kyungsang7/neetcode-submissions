class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 1){
            return 0;
        }

        vector<int> pre(height.size());
        vector<int> suf(height.size());
        pre[0] = height[0];
        suf[height.size() - 1] = height[height.size() - 1];

        for(int i = 1; i < height.size(); i++){
            pre[i] = max(pre[i - 1], height[i]);
        }

        for(int i = height.size() - 2; i >= 0; i--){
            suf[i] = max(suf[i + 1], height[i]);
        }

        int ans = 0;
        for(int i = 1; i < height.size() - 1; i++){
            if(min(pre[i], suf[i]) > height[i]){
                ans += min(pre[i], suf[i]) - height[i];    
            }
        }
        return ans;
    }
};
