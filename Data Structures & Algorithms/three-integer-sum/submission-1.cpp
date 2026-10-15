class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int left = 0, right = nums.size() - 1;
                while(left <= right){
                    int mid = (left + right) / 2;
                    int key_num = nums[mid] + nums[i] + nums[j];

                    if(key_num > 0){
                        right = mid - 1;
                    }
                    else if(key_num < 0){
                        left = mid + 1;
                    }
                    else{
                        if(mid == i || mid == j){
                            break;
                        }
                        vector<int> arr = {nums[mid], nums[i], nums[j]};
                        sort(arr.begin(), arr.end());
                        res.insert(arr);
                        break;
                    }
                }
            }
        }
        vector<vector<int>> s;
        for(auto r:res){
            s.push_back(r);
        }
        return s;
    }
};
