class Solution {
public:
    int binaryGap(int n) {
        int last = -1;   // last position jahan '1' mila
        int ans = 0;     // maximum gap
        int pos = 0;     // current bit position (right se)

        while (n > 0) {
            if (n & 1) {              // agar current bit = 1 hai
                if (last != -1) {     // agar pehle bhi koi 1 mila tha
                    ans = max(ans, pos - last);
                }
                last = pos;           // current position ko store karo
            }
            pos++;                    // next bit position
            n >>= 1;                  // right shift (next bit check)
        }
        return ans;
    }
};