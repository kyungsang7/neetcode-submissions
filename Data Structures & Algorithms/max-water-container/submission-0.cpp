class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int left = 0, right = heights.size() - 1;
        while(left < right){
            ans = max(ans, (right - left) * min(heights[left], heights[right]));
            if (heights[left] > heights[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};
