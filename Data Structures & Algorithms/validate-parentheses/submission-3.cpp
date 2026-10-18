class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(char n:s){
            if(n == '[' || n == '{' || n == '('){
                sta.push(n);
                continue;
            }
            if(sta.size() == 0){
                return false;
            }
            else if(n == ')'){
                if(sta.top() != '('){
                    return false;
                }
            }
            else if(n == ']'){
                if(sta.top() != '['){
                    return false;
                }
            }
            else if(n == '}'){
                if(sta.top() != '{'){
                    return false;
                }
            }
            sta.pop();
        }
        if(sta.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};