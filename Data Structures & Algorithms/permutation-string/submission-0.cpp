class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> table(26,0);
        vector<int> window(26,0);

        for(char a:s1){
            table[a - 'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            window[s2[i] - 'a']++;
            if(i >= s1.size()){
                window[s2[i - s1.size()] - 'a']--;
            }
            if (table == window){
                return true;
            }
        }
        return false;
    }
};
