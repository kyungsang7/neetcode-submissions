class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for(char& c:t){
            hash[c]++;
        }

        int need = t.size();
        int left = 0, right = 0;
        pair<int, int> ans = {-1, -1};
        int anssize = INT_MAX;

        while(right < s.size()){
            if (hash.count(s[right])){
                hash[s[right]]--;
                if (hash[s[right]] >= 0){
                    need--;
                }
            }

            while(need == 0){
                if(right - left + 1 < anssize){
                    ans = {left, right};
                    anssize = right - left + 1;
                }

                if(hash.count(s[left])){
                    hash[s[left]]++;
                    if(hash[s[left]] > 0){
                        need++;
                    }
                }
                left++;
            }
            right++;
        }

        return ans.first == -1 ? "" : s.substr(ans.first, ans.second - ans.first + 1);
    }
};
