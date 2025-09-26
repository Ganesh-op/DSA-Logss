class Solution {
public:
    bool binary_search(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return true;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = 0;
        if (nums[l] >= nums[r]) {
            while (l < r) {
                m = l + (r - l) / 2;
                while (nums[l] == nums[r] && nums[m] == nums[r] && m > l)
                    ++l;
                if (nums[m] < nums[r])
                    r = m;
                else if (nums[m] > nums[r])
                    l = m + 1;
                else
                    --r;
            }
        }
        int pivot = r;
        return (binary_search(nums, target, 0, pivot - 1) ||
                binary_search(nums, target, pivot, nums.size() - 1));
    }
};