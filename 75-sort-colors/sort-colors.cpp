class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, i = 0;

        while (i <= hi) {
            if (nums[i] == 0) {
                std::swap(nums[lo], nums[i]);
                lo++;
                i++;
            }

            else if (nums[i] == 2)
                {
                    std::swap(nums[i], nums[hi--]);
                }
            else if (nums[i] == 1)
                i++;
        }
    }
};