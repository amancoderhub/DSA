class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int totalProd = 1;
        int zeroCount = 0;
        //calculate total prod without zero and also zero count 
        for(int i = 0;i<n;i++){
           if(nums[i]==0){
              zeroCount++;
           }else{
             totalProd *= nums[i];
           }
        };
        //update the ans array according to the condition
        for(int i = 0;i<n;i++){
            //if zero count is more then one then all arr become zero
            if(zeroCount>1){
               ans[i] = 0;
            }
            //if zero count is only one then replace zero with total prod
            else if(zeroCount==1){
               if(nums[i]==0){
                 ans[i] = totalProd;
               }
            //if zeroCount equal to 0 then total prodct add by apply deviosn by nums arr
            }else{
                ans[i] = totalProd/nums[i];
            } 
        }
        return ans;
    }
};