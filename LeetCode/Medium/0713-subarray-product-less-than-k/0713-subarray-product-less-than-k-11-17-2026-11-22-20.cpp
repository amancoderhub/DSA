class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //brute force
        if(k<=1) return 0;
        int n= nums.size();
        int count = 0;
        int prod = 1;
        int l = 0;
        for(int r= 0;r<n;r++){
            prod *= nums[r];
            while(prod>=k){
                prod /= nums[l];
                l++;
            }
            count += r-l+1;
        }
        return count;
    }
};