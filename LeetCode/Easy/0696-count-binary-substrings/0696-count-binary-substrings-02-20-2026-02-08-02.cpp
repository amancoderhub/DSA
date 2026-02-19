class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int res = 0;
        int prev = 0;
        int streak = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) streak++;
            else {
                prev = streak;
                streak = 1;
            }
            if (streak <= prev) res++;
        }
        return res;
    }
};
