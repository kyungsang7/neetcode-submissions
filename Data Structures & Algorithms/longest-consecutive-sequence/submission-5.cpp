class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> store(nums.begin(), nums.end());

        for(int num:nums){
            int streak = 0, cur = num;
            if(store.count(num - 1)){
                continue;
            }
            while(store.count(cur)){
                cur++;
                streak++;
            }
            res = max(res, streak);
        }
        return res;
    }
};