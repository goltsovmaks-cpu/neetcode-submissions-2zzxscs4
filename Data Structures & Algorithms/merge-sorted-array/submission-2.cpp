class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* I though about 2 ways
            1) just shift nums1 -> (to fill placehoulders) and sort like 2 arrays, there is no collisions here
        
            2) this more complex, but faster - we iterate over nums1 and swap items like

            [3,10,15...]
            [5,7,9, 10, 15]
            ->
            [3 5 7, ...] 
            [10, 15, 9 10, 15]
            ------ptr|
            when resolve itervals.

            In this case we dont need to shift our nums1 (save some cpu) but...
        */

        // 3) JUST SORT FROM ENDING!!!!

        int p1 = m - 1;
        int p2 = n - 1;
        int toPut = nums1.size() - 1;
        while(p2 >= 0) {
            if (p1 >=0 && nums1[p1] > nums2[p2]) {
                nums1[toPut] = nums1[p1];
                p1--;
            } else {
                nums1[toPut] = nums2[p2];
                p2--;
            }
            toPut--;
        }

        // int idxFirst = m-1;
        // int idxSecond = n-1;
        // for (int i = nums1.size()-1; i >= 0; i--) {
        //     if (idxSecond < 0) {
        //         return;
        //     }

        //     if (idxFirst >= 0 && nums1[idxFirst] > nums2[idxSecond]) {
        //         nums1[i] = nums1[idxFirst];
        //         idxFirst--;
        //     } else {
        //         nums1[i] = nums2[idxSecond];
        //         idxSecond--;
        //     }
        // }
    }
};