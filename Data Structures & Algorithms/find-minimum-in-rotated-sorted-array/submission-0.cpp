class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int ans = min(nums[left], nums[right]);

        while (left <= right){
            int mid = (left + right) / 2;
            int mid_val = nums[mid];
            if (mid_val > ans){
                left = mid + 1;
            }
            else{
                right = mid - 1;
                ans = mid_val;
            }
        }
        return ans;
    }
};
