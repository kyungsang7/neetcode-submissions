class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        int res = 0;
        for(int num:nums){
            if(!hash[num]){
                hash[num] = hash[num - 1] + hash[num + 1] + 1;
                hash[num - hash[num - 1]] = hash[num];
                hash[num + hash[num + 1]] = hash[num];
                res = max(res, hash[num]);
            }
        }
        return res;
    }
};
