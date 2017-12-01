class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while(1){
            if(mid % 2 == 0){
                if(mid < nums.size() - 1 && nums[mid] == nums[mid+1]) left = mid + 2;
                else if(mid > 0 && nums[mid] == nums[mid-1]) right = mid - 1;
                else return nums[mid];
            }
            else{
                if(mid < nums.size() - 1 && nums[mid] == nums[mid+1]) right = mid - 1;
                else if(mid > 0 && nums[mid] == nums[mid-1]) left = mid + 1;
                else return nums[mid];
            }
            mid = (left + right) / 2;
        }
    }
};