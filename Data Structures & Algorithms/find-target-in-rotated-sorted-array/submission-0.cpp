class Solution {
public:
    int get_ans(vector<int>& nums, int left, int right, int tar){
        while(left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] > tar){
                right = mid - 1;
            }
            else if(nums[mid] < tar){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int min_idx = 0, min_val = nums[0];

        while (left <= right){
            int mid = (left + right) / 2;
            int mid_val = nums[mid];
            if (mid_val < min_val){
                right = mid - 1;
                min_val = mid_val;
                min_idx = mid;
            }
            else{
                left = mid + 1;
            }
        }
        int ans = get_ans(nums, 0, min_idx - 1, target);
        if(ans != -1){
            return ans;
        }
        int ans2 = get_ans(nums, min_idx, nums.size() - 1, target);
        return ans2;
    }
};
