class Solution {
public:
    
    static bool compare(pair<int, int> a, pair<int, int> b){
        return (a.first < b.first);
    }
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
        if(n == 0) return people;
        
        vector<pair<int, int>> result(n, pair<int, int>(-1, -1));
        
        sort(people.begin(), people.end(), compare);
        
        for(int i = 0; i < n; i++){
            int count = people[i].second;
            for(int j = 0; j < n; j++){
                if(result[j].first == -1){
                    if(count <= 0){
                        result[j] = people[i];
                        break;
                    }
                    else count--;
                }
                else if(result[j].first >= people[i].first){
                    count--;
                }
            }
        }
        
        return result;
    }
};