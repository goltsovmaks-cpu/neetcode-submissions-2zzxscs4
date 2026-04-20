class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool firstIsShorter = nums1.size() < nums2.size();
        vector<int>& shorter = firstIsShorter ? nums1 : nums2;
        vector<int>& longer = firstIsShorter ? nums2 : nums1;

        int l = 0;
        int r = shorter.size() - 1;

        int total = shorter.size() + longer.size();
        int half = total / 2;

        double ans = 0;

        while (true) {
            int m = l + (int)std::floor((double)(r - l) / 2); 

            int leftEndShort = m >= 0 ? shorter[m] : INT_MIN;
            int rightBeginShort = (m + 1) < shorter.size() ? shorter[m+1] :  INT_MAX; 

            int idx = half - m - 2;

            int leftEndLong = idx >= 0 ? longer[idx] : INT_MIN ;
            int rightBeginLong = (idx + 1) < longer.size() ? longer[idx + 1] : INT_MAX ;

            if (leftEndShort > rightBeginLong) {
                r = m - 1;
                continue;
            }

            if (leftEndLong > rightBeginShort) {
                l = m + 1;
                continue;
            }

            int maxLeft = max(leftEndShort, leftEndLong);
            int minRight = min(rightBeginShort, rightBeginLong);
            if (total & 1) { // odd (нечетное)
                ans = minRight;
            } else { // even (чет)
                ans = static_cast<double>(maxLeft + minRight) / 2;
            }
            break;    
        }

        return ans;
    }
};
