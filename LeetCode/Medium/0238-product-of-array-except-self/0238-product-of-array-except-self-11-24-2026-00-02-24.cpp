class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        res[0] = 1;
        for(int l = 1;l<n;l++){
            res[l]= res[l-1] * nums[l-1];
        }
        int rPro = 1;
        for(int r = n-1;r>=0;r--){
           res[r]= res[r] * rPro;
           rPro *= nums[r]; 
        }
        return res;
    }
};