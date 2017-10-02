class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            int tem = 0;
            if(nums[i] == i+1) continue;
            temp = nums[i];
            nums[i] = -1;
            while(true){
                tem = nums[temp-1];
                nums[temp-1] = temp;
                if(tem == -1) break;
                if(tem == temp){
                    result.push_back(tem);
                    break;
                }
                temp = tem;
            }
        }
        return result;
    }
};