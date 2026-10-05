class Solution {
public:
    int maxArea(vector<int>& arr) {
    int n = arr.size();
    //Two Pointer i,j
    int i = 0;
    int j = n-1;
    int total = 0;
    while(i<j){
        int h = min(arr[i], arr[j]);
        int w = j-i;
        int area = h * w;
        total = max(total, area);
        if(arr[j]<arr[i]){
            j--;
        }else{
            i++;
        }
    }
    return total;
    }
};