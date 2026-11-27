class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int maxSum = nums[0];
        int currMax = 0;
        int minSum = nums[0];
        int currMin = 0;
        for(int i = 0;i<n;i++){
            // Kadane's algo for max sum 
           currMax = max(nums[i], currMax + nums[i]);
           maxSum = max(maxSum, currMax);
           // Inverted Kadane's algo for min sum 
           currMin = min(nums[i], currMin + nums[i]);
           minSum = min(minSum, currMin);
           
           totalSum += nums[i];
        }
        if (maxSum < 0) {
            return maxSum;
        }
        return max(maxSum , totalSum - minSum);
    }
};