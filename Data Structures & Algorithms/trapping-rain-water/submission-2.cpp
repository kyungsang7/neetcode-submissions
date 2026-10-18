class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftmax = height[left], rightmax = height[right];
        int ans = 0;

        while(left < right){
            if(height[left] > height[right]){
                right--;
                if(height[right] < rightmax){
                    ans += rightmax - height[right];
                }
                else{
                    rightmax = height[right];
                }
            }
            else{
                left++;
                if(height[left] < leftmax){
                    ans += leftmax - height[left];
                }
                else{
                    leftmax = height[left];
                }
            }
        }
        return ans;
    }
};
