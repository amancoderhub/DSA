class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = n-1;
        int maxW = 0;
        while(i<j){
            int h = min(arr[i],arr[j]);
            int A  = h * (j-i);
            maxW =  max(maxW, A);
            if(arr[j]<arr[i]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxW;
    }
};