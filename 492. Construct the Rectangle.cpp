class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result;
        int L = 0;
        int W = 0;
        for(L = sqrt(area); L <= area; L++){
            W = area / L;
            if(W * L == area && L >= W) break;
        }
        result.push_back(L);
        result.push_back(W);
        return result;
    }
};