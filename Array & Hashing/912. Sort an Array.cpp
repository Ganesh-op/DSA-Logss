class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }

    void quick(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int s = low, e = high;
        int mid = (s + e) / 2;
        int pivot = nums[mid];

        while (s <= e) {
            while (nums[s] < pivot) s++;
            while (nums[e] > pivot) e--;
            if (s <= e) {
                swap(nums[s], nums[e]);
                s++;
                e--;
            }
        }

        quick(nums, low, e);
        quick(nums, s, high);
    }
};