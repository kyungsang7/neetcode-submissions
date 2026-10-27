class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> heap;
        for (int i = 0; i < position.size(); i++){
            heap.push({position[i], speed[i]});
        }

        int ans = 0;
        double rec = 0;

        while(!heap.empty()){
            double time = (double)(target - heap.top().first) / heap.top().second;
            if (time > rec){
                ans++;
                rec = time;
            }
            heap.pop();
        }
        return ans;
    }
};
