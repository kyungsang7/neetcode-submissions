class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(const string& token:tokens){
            if(isdigit(token[token.size() - 1])){
                stk.push(stoi(token));
            }
            else if(token == "+"){
                int res = stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
                stk.push(res);
            }
            else if(token == "-"){
                int res1 = stk.top();
                stk.pop();
                int res2 = stk.top();
                stk.pop();
                stk.push(res2 - res1);
            }
            else if(token == "*"){
                int res = stk.top();
                stk.pop();
                res *= stk.top();
                stk.pop();
                stk.push(res);
            }
            else if(token == "/"){
                int res1 = stk.top();
                stk.pop();
                int res2 = stk.top();
                stk.pop();
                stk.push(res2 / res1);
            }
        }
        return stk.top();
    }
};
