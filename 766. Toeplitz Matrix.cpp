class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m <= 1) return true;
        int n = matrix[0].size();
        int val[50];
        for(int i = 0; i < 50; i++) val[i] = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int index = i - j + 20;
                if(val[index] == -1) val[index] = matrix[i][j];
                else if(val[index] != matrix[i][j]) return false;
            }
        }
        return true;
    }
};