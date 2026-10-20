class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // Brute Force aaproach 
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-2;i++){
            //skip duplicate for the first element
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int j = i+1;
            int k = n-1;
            while(j<k){
              int sum = nums[i]+nums[j]+nums[k];
              if(sum == 0){
                ans.push_back({nums[i],nums[j],nums[k]});
                //skip duplicate for j pointer
                while(j<k && nums[j] == nums[j+1]){
                    j++;
                }//skip duplicate for k pointer 
                while(j<k && nums[k] == nums[k-1]){
                    k--;
                }
                j++;
                k--;
              }
              else if(sum<0) j++;
              else k--;
            }
        }
        return ans;
    }
};