class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
                while(!stk.empty() && height[i] >= height[stk.top()]){
                    int mid = stk.top();
                    int midvalue = height[mid];
                    stk.pop();
                    
                    if(stk.empty()){
                        break;
                    }

                    int left = stk.top();
                    int leftvalue = height[left];
                    int right = i;
                    int rightvalue = height[right];
                    int h = min(leftvalue, rightvalue) - midvalue;
                    int w = right - left - 1;
                    ans += h * w;

                }
            stk.push(i);
        }
        return ans;
    }
};
