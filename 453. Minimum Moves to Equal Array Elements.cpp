class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        auto min = min_element(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i <nums.size(); i++){
            sum = sum + nums[i];
        }
        return sum - (*min) * nums.size();
    }
};