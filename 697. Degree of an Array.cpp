class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int count[50000];
        int first[50000];
        int last[50000];
        for(int i = 0; i < 50000; i++){
            count[i] = 0;
            first[i] = -1;
            last[i] = -1;
        }
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
            if(first[nums[i]] == -1) first[nums[i]] = i;
            last[nums[i]] = i;
        }
        int max = -1;
        int distance = 50000;
        for(int i = 0; i < 50000; i++){
            if(count[i] > max || ((count[i] == max) && last[i]-first[i]+1 < distance)){
                max = count[i];
                distance = last[i] - first[i] + 1;
            }
        }
        return distance;
    }
};