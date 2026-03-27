class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            //Odd length palindrome
            expand(s, i, i, start, maxLen);

            //Even length palindrome
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
private:
    void expand(string &s, int left, int right, int &start, int &maxLen) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;

            if (len > maxLen) {
                start = left;
                maxLen = len;
            }

            left--;
            right++;
        }
    }
};