class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int left = 0, right = 0;

        while(left < prices.size() - 1){
            if (left == right){
                right++;
            }
            else if (right == prices.size() - 1){
                ans = max(ans, prices[right] - prices[left]);
                left++;
            }
            else if (prices[right] - prices[left] > 0){
                ans = max(ans, prices[right] - prices[left]);
                right++;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};
