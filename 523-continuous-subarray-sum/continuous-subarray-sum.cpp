class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = -1;
        int perfixSum = 0;
        for(int i = 0;i<n;i++){
           perfixSum += nums[i];
           int rem = perfixSum % k;
           if(rem < 0 ){
             rem+= k;
           }
           if(mp.count(rem)){
            if(i-mp[rem] >= 2){
                return true;
            }
           }else{
              mp[rem] = i;
            }
        }
        return false;
    }
};