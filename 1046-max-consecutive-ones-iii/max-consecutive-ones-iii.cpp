class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //sliding windows
        int n = nums.size();
        int l = 0;
        int max_len = 0;
        int zerocount = 0;
        for(int r = 0; r<n;r++){
            if(nums[r] == 0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[l]==0) zerocount--;
                l++;
            }
            max_len = max(max_len, r-l+1);
        }
        return max_len;
    }
};