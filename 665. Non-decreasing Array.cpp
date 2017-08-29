class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool used = false;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(used == true) return false;
                if(i+1 == nums.size()-1) return true;
                if(nums[i+2] >= nums[i]) used = true;
                else if(i == 0) used = true;
                else if(nums[i-1] <= nums[i+1]) used = true;
                else return false;
            }
        }
        return true;
    }
};