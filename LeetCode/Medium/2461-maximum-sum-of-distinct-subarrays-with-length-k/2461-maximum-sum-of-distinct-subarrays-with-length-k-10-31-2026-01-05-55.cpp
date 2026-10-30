class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_ans = 0;
        long long w_sum = 0;
        // Tracks element frequencies in the window
        unordered_map<int, int> count; 

        // 1. Build the initial window of size k
        for (int i = 0; i < k; i++) {
            w_sum += nums[i];
            count[nums[i]]++;
        }

        // Check if the initial window contains all distinct elements
        if (count.size() == k) {
            max_ans = w_sum;
        }

        // 2. Slide the window across the rest of the array
        for (int j = k; j < n; j++) {
            // Add the new incoming element
            w_sum += nums[j];
            count[nums[j]]++;

            // Remove the outgoing element from the back of the window
            w_sum -= nums[j - k];;
            count[nums[j - k]]--;
            
            // Clean up map key if frequency reaches 0
            if (count[nums[j - k]] == 0) {
                count.erase(nums[j - k]);
            }

            // If the map size equals k, it means all elements in the window are unique
            if (count.size() == k) {
                max_ans = max(max_ans, w_sum);
            }
        }

        return max_ans;
    }
};
