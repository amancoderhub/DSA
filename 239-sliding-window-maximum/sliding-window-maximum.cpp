#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1);
        deque<int> dq; // Stores indices

        for (int right = 0; right < n; right++) {
            // 1. Remove indices that are out of the current window
            while (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // 2. Remove indices whose values are smaller than nums[right]
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }

            // 3. Add current index to the back
            dq.push_back(right);

            // 4. Record the maximum once the first window of size k is complete
            if (right >= k - 1) {
                result[right - k + 1] = nums[dq.front()];
            }
        }

        return result;
    }
};
