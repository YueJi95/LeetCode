class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int n = height.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int temp = high - low;
            if(height[low] <= height[high]){
                temp = temp * height[low];
                low++;
            }
            else{
                temp = temp * height[high];
                high--;
            }
            if(temp > max) max = temp;
        }
        return max;
    }
};