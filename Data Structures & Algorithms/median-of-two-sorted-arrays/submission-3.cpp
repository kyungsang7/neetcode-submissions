class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int half = (A.size() + B.size()) / 2;
        if (B.size() < A.size()){
            swap(A, B);
        }

        int left = 0, right = A.size();
        while(left <= right){
            int amid = (left + right) / 2;
            int bmid = half - amid;

            int aleft = amid - 1 >= 0 ? A[amid - 1] : INT_MIN;
            int aright = amid < A.size() ? A[amid] : INT_MAX;
            int bleft = bmid - 1 >= 0 ? B[bmid - 1] : INT_MIN;
            int bright = bmid < B.size() ? B[bmid] : INT_MAX;

            if (aleft <= bright && bleft <= aright){
                if((A.size() + B.size()) % 2 == 1){
                    return min(aright, bright);
                }
                return double(max(aleft, bleft) + min(aright, bright)) / 2;
            }else if (aleft > bright){
                right = amid - 1;
            }else{
                left = amid + 1;
            }
        }
        return -1;
    }
};
