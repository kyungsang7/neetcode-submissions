class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for (string str : strs){

            vector<int> count(26, 0);
            for(char c:str){
                count[c-'a']++;
            }

            string key = "";
            for(int a:count){
                key += to_string(a) + "_";
            }

            hash[key].push_back(str);

        }

        vector<vector<string>> ans;
        for (auto& push:hash){
            ans.push_back(push.second);
        }

        return ans;

    }
};
