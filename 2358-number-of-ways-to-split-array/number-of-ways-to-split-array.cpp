class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
         int validSpitls = 0;
    int n = nums.size();
    std::vector<long> sumr(n);
    std::vector<long> suml(n);

    suml[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        suml[i] = nums[i] + suml[i-1];
    }

    for (int i = 0; i < n-1; i++)
    {
        long leftSum=suml[i];

        long rightSum=suml[n-1]-suml[i];

        if (leftSum >= rightSum)
            validSpitls++;
    }

    return validSpitls;
    }
};