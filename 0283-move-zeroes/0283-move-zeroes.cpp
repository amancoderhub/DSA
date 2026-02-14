class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;   // safety check

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < n; j++) {
                    nums[j - 1] = nums[j];
                }
                nums[n - 1] = 0;
                n--;

                if (i > 0) i--;   // avoid negative index
                else i = -1;      // safe reset
            }
        }
    }
};
