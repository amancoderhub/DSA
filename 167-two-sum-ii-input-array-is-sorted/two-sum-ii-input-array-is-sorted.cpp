class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            int sum = num[left]+num[right];
            if(target == sum){
                return {left+1, right+1};
            }
            else if(sum>target) right--;
            else left++;
        }
        return {};
    }
};