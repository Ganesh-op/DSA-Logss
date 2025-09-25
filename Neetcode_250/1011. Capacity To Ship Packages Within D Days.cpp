class Solution {
public:
    bool isPossible(const vector<int>& weights, int days, int capacity) {
        int days_needed = 1;
        int current_load = 0;
        for (int weight : weights) {
            if (weight > capacity)
                return false;

            if (current_load + weight > capacity) {
                days_needed++;
                current_load = weight;
            } else {
                current_load += weight;
            }
        }
        return days_needed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};