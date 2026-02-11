class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> segSum, segMin, segMax, lazy;
        vector<bool> mark;

        SegmentTree(int sz) {
            n = sz;
            segSum.assign(4 * n + 5, 0);
            segMin.assign(4 * n + 5, 0);
            segMax.assign(4 * n + 5, 0);
            lazy.assign(4 * n + 5, 0);
            mark.assign(4 * n + 5, false);
        }

        void mergeNode(int idx) {
            segSum[idx] = segSum[idx << 1] + segSum[idx << 1 | 1];
            segMin[idx] = min(segMin[idx << 1], segSum[idx << 1] + segMin[idx << 1 | 1]);
            segMax[idx] = max(segMax[idx << 1], segSum[idx << 1] + segMax[idx << 1 | 1]);
        }

        void apply(int idx, int l, int r, int val) {
            int len = r - l + 1;
            segSum[idx] = val * len;

            if (val == 0) {
                segMin[idx] = 0;
                segMax[idx] = 0;
            } else if (val > 0) {
                segMin[idx] = val;
                segMax[idx] = val * len;
            } else {
                segMin[idx] = val * len;
                segMax[idx] = val;
            }

            mark[idx] = true;
            lazy[idx] = val;
        }

        void pushDown(int idx, int l, int r) {
            if (!mark[idx] || l == r) return;
            int mid = (l + r) >> 1;
            apply(idx << 1, l, mid, lazy[idx]);
            apply(idx << 1 | 1, mid + 1, r, lazy[idx]);
            mark[idx] = false;
        }

        void updatePoint(int pos, int val) {
            update(1, 0, n - 1, pos, pos, val);
        }

        void update(int idx, int l, int r, int ql, int qr, int val) {
            if (ql <= l && r <= qr) {
                apply(idx, l, r, val);
                return;
            }
            pushDown(idx, l, r);
            int mid = (l + r) >> 1;
            if (ql <= mid) update(idx << 1, l, mid, ql, qr, val);
            if (qr > mid) update(idx << 1 | 1, mid + 1, r, ql, qr, val);
            mergeNode(idx);
        }

        int findPos(int target) {
            if (target == 0) return -1;
            if (target < segMin[1] || target > segMax[1]) return n;
            int pref = 0;
            return findPos(1, 0, n - 1, target, pref);
        }

        int findPos(int idx, int l, int r, int target, int &pref) {
            if (l == r) {
                if (pref + segSum[idx] == target) return l;
                return n;
            }

            pushDown(idx, l, r);

            int mid = (l + r) >> 1;
            int left = idx << 1;
            int right = idx << 1 | 1;

            int low = pref + segMin[left];
            int high = pref + segMax[left];

            if (target >= low && target <= high) {
                return findPos(left, l, mid, target, pref);
            } else {
                pref += segSum[left];
                return findPos(right, mid + 1, r, target, pref);
            }
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int mxVal = 0;
        for (int x : nums) mxVal = max(mxVal, x);
        mxVal++;

        vector<int> last(mxVal, -1);
        SegmentTree tree(n);

        int curSum = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (last[nums[i]] != -1) {
                tree.updatePoint(last[nums[i]], 0);
            } else {
                if (nums[i] & 1) curSum++;
                else curSum--;
            }

            last[nums[i]] = i;

            if (nums[i] & 1) tree.updatePoint(i, 1);
            else tree.updatePoint(i, -1);

            int pos = tree.findPos(curSum);
            res = max(res, i - pos);
        }

        return res;
    }
};
