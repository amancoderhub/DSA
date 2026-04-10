class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);

            if (mp[nums[i]].size() >= 3) {
                int sz = mp[nums[i]].size();
                int a = mp[nums[i]][sz - 3];
                int c = mp[nums[i]][sz - 1];

                ans = min(ans, 2 * (c - a));
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};