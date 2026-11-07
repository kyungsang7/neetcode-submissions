class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> heap;
        for(int i = 0; i < k; i++){
            heap.push({nums[i], i});
        }

        int left = 0;
        vector<int> ans(nums.size() - k + 1, 0);
        for(int i = k; i < nums.size() + 1; i++){
            while(heap.top().second < left){
                heap.pop();
            }
            ans[left] = heap.top().first;
            left++;
            if(i < nums.size()){
                heap.push({nums[i], i});
            }
        }     
        return ans;
    }
};
