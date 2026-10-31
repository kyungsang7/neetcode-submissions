class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int ans = 0, res = 0;
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            if (hash.find(c) == hash.end() || hash[c] < res){
                hash[c] = i;
            }
            else{
                res = hash[c] + 1;
                hash[c] = i;
            }
            ans = max(ans, i - res + 1);
        }
        return ans;
    }
};
