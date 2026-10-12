class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(string str:strs){
            res += str;
            res += "~";
        }

        return res;

    }

    vector<string> decode(string s) {
        vector<string> ans;

        string res = "";
        for(char a:s){
            if(a == '~'){
                ans.push_back(res);
                res = "";
            }
            else{
                res += a;
            }
        }
        return ans;
    }
};
