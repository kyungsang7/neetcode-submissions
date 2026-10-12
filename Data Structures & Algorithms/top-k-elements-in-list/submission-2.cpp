class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i:nums){
            hash[i]++;
        }
        
        vector<vector<int>> freq(nums.size() + 1);
        for(const auto& push:hash){
            freq[push.second].push_back(push.first);
        }

        vector<int> ans;
        for(int i = nums.size(); i > 0; i--){
            for(int j:freq[i]){
                ans.push_back(j);
                if (ans.size() == k){
                    return ans;
            }
        }

        }
        return ans;
    }
};
