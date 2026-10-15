class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char st:s){
            if(isalnum(st)){
                str += tolower(st);
            }
        }
        int left = 0, right = str.size() - 1;
        while(left < right){
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
