class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1 && nums[i] > 0){
                int pos = nums[i] - 1;
                nums[i] = -1;
                while(nums[pos] != pos + 1 && pos >= 0){
                    int temp = nums[pos];
                    nums[pos] = pos + 1;
                    pos = temp - 1;
                }
            }
        }
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) result.push_back(i+1);
        }
        return result;
    }
};