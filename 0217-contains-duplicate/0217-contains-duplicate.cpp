class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int x : nums){
            if(mp.count(x)){
                return true;
            }
            mp[x]++;
        }
        return false;
    }
};