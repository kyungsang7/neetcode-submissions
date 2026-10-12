class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int num:nums){
            hash[num]++;
        }

        vector<pair<int, int>> res;
        for(auto& push:hash){
            res.push_back({push.second, push.first});
        }

        sort(res.begin(), res.end(), greater<pair<int, int>>());

        vector<int> ans;

        for(int i = 0; i < k ; i++){
            ans.push_back(res[i].second);
        }

        return ans;


    }
};
