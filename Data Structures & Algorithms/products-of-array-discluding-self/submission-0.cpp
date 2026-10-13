class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int num = 1;
        for(int i = 1; i < nums.size(); i++){
            num *= nums[i - 1];
            ans[i] *= num;
        }

        num = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            num *= nums[i + 1];
            ans[i] *= num;
        }

        return ans;
    }
};
