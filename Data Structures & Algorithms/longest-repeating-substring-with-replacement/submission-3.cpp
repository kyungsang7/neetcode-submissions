class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int ans = 0;

        while (right < s.size()) {
            mp[s[right]]++;

            int sum = 0;
            int max_freq = 0;

            for (auto& p : mp) {
                sum += p.second;
                max_freq = max(max_freq, p.second);
            }

            while (sum - max_freq > k) {
                mp[s[left]]--;
                left++;
                sum--;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};