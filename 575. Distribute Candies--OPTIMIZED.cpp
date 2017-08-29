class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int count = 0;
        vector<bool> types(200010, false);
        for(int i = 0; i < candies.size(); i++){
            if(types[candies[i]+100000] == false){
                count++;
                types[candies[i]+100000] = true;
                if(count >= candies.size() / 2) return candies.size() / 2;
            }
        }
        return count;
    }
};