class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        while (left <= right){
            int mid = (left + right) / 2;
            
            long res = 0;
            for (int i = 0; i < piles.size(); i++){
                res += (piles[i] + mid - 1) / mid;
            }

            if (res <= h){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
