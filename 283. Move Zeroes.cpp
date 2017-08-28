class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numz = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)    numz++;
            else{
                nums[i-numz] = nums[i];
                if(numz > 0)    nums[i] = 0;
            }
        }
    }
};