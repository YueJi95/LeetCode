class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result(findNums.size(), -1);
        vector<int> list(1001, 0);
        for(int i = 0; i < nums.size(); i++){
            list[nums[i]] = i;
        }
        for(int i = 0; i < findNums.size(); i++){
            int index = list[findNums[i]];
            for(int j = index; j < nums.size(); j++){
                if(nums[j] > findNums[i]){
                    result[i] = nums[j];
                    break;
                }
            }
        }
        return result;
    }
};