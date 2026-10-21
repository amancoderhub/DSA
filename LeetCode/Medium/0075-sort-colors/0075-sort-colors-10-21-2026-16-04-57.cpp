class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //optimize ONE pass solution using the three pointer 
        int low = 0, mid = 0, high = n-1;
        while(mid<=high){
            // 0 to low-1
            if(nums[mid]==0){
                nums[mid] = nums[low];
                nums[low] = 0;
                low++;
                mid++;
            }//low to mid-1
            else if(nums[mid]== 1){
                mid++;
            }//high+1 to n-1
            else{//swap the mid and high
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high--;
            }
        }
        return;
    }
};