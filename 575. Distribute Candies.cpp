class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int count = 0;
        vector<int> types;
        for(int i = 0; i < candies.size(); i++){
            bool exist = false;
            for(int j = 0; j < types.size(); j++){
                if(types[j] == candies[i]){
                    exist = true;
                    break;
                }
            }
            if(exist == false){
                types.push_back(candies[i]);
                count++;
                if(count >= candies.size()/2) return candies.size()/2;
            }
        }
        return count;
    }
};