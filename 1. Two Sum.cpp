class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> save(nums);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            
            if((i > 0) && (nums[i] == nums[i-1])) continue;
            
            int val = target - nums[i];
            int left = i + 1;
            int right = n - 1;
            int mid = (left + right) / 2;
            int index = -1;
            
            while(left <= right){
                mid = (left + right) / 2;
                if(nums[mid] == val){
                    index = mid;
                    break;
                }
                else if(nums[mid] < val) left = mid + 1;
                else right = mid - 1;
                
            }
            
            if(index != -1){
                bool flag = false;
                for(int j = 0; j < n; j++){
                    if(nums[i] == save[j]){
                        result.push_back(j);
                        if(flag) return result;
                        else flag = true;
                    }
                    else if(nums[index] == save[j]){
                        result.push_back(j);
                        if(flag) return result;
                        else flag = true;
                    }
                }
            }
        }
        
        return result;
    }
};