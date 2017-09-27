class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mmin = m;
        int nmin = n;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i][0] < mmin) mmin = ops[i][0];
            if(ops[i][1] < nmin) nmin = ops[i][1];
        }
        return mmin * nmin;
    }
};