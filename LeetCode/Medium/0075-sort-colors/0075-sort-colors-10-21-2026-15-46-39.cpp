class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //Brute Force approach 
        int countZero = 0;
        int countOne = 0;
        int countTwo = 0;
        for(int i =0;i<n;i++){
            if(nums[i]==0) countZero++;
            else if(nums[i]==1) countOne++;
            else countTwo++;
        }
        int idx = 0;
        while(countZero>0){
            nums[idx] = 0;
            idx++;
            countZero--;
        }
        while(countOne>0){
            nums[idx] = 1;
            idx++;
            countOne--;
        }
        while(countTwo>0){
            nums[idx] = 2;
            idx++;
            countTwo--;
        }
        return;
    }
};