class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int n = height.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && height[i] <= height[i-1]) continue;
            for(int j = n-1; j > i; j--){
                if(j < n-1 && height[j] <= height[j+1]) continue;
                int temp = j - i;
                if(height[i] >= height[j]) temp = temp * height[j];
                else temp = temp * height[i];
                if(temp > max) max = temp;
            }
        }
        return max;
    }
};