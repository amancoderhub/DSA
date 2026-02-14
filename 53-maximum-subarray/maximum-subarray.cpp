class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long n = nums.size();
        long long maxi = nums[0];
        long long sum =0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            maxi=max(sum,maxi);

            if(sum<0) sum = 0;
        }
        return maxi;
    }
};