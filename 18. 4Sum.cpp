class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int val1 = target - nums[i];
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int val2 = val1 - nums[j];
                for(int k = j+1; k < n; k++){
                    if(k > j+1 && nums[k] == nums[k-1]) continue;
                    int val3 = val2 - nums[k];
                    int left = k + 1;
                    int right = n - 1;
                    int mid = (left + right) / 2;
                    int index = -1;
                    
                    while(left <= right){
                        mid = (left + right) / 2;
                        if(nums[mid] == val3){
                            index = mid;
                            break;
                        }
                        else if(nums[mid] < val3) left = mid + 1;
                        else right = mid - 1;
                    }
                    
                    if(index != -1){
                        vector<int> add;
                        add.push_back(nums[i]);
                        add.push_back(nums[j]);
                        add.push_back(nums[k]);
                        add.push_back(nums[index]);
                        result.push_back(add);
                    }
                }
            }
        }
        
        return result;
    }
};