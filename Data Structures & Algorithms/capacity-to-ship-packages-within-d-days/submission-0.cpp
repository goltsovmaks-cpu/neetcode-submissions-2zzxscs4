class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *ranges::max_element(weights);
        // or max * (ceil(size() /days)) if most weighs close to max
        int right = std::accumulate(weights.begin(), weights.end(), 0);

        int capacity = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int crntSum = 0;
            int crntDays = 1;
            for (size_t i = 0; i < weights.size(); i++) {
                int w = weights[i];
                crntSum += w;
                if (crntSum == mid && i < weights.size() - 1) { 
                    crntDays++;
                    crntSum = 0;
                } else if (crntSum > mid) {
                    crntDays++;
                    crntSum = w;
                }
            }

            if (crntDays > days) { // too smal capacity
                left = mid + 1;
            } else { 
                capacity = min(capacity, mid);
                right = mid - 1;
            }
        }
        return capacity;
    }
};








