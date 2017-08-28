class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int vsum = 0;
        int oc = nums[0].size();
        for(int i = 0; i < nums.size(); i++)    vsum = vsum + nums[i].size();
        if(vsum != r * c)   return nums;
        vector<vector<int> > result(r, vector<int>(c));
        for(int i = 0; i < r * c; i++)   result[i / c][i % c] = nums[i / oc][i % oc];
        return result;
    }
};