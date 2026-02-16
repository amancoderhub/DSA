class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int x : nums){
            st.insert(x);
        }
        int m = st.size();
        if(m<n) return true;
        return false;
    }
};