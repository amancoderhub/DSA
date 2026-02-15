class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;   // value -> count
        for (int x : nums) {
            mp[x]++;     // increase count

            if (mp[x] > 1)        // already seen before
                return x;         // duplicate found
        }
        return -1;
    }
};
