class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int> > N(M.size(), vector<int>(M[0].size()));
        for(int i = 0; i < M.size(); i++){
            for(int j = 0; j < M[0].size(); j++){
                int sum = M[i][j];
                int count = 1;
                int n = M[0].size();
                int m = M.size();
               
                if(i-1 >= 0 && j-1 >= 0){
                    sum = sum + M[i-1][j-1];
                    count++;
                }
                if(j-1 >= 0){
                    sum = sum + M[i][j-1];
                    count++;
                }
                if(i-1 >= 0){
                    sum = sum + M[i-1][j];
                    count++;
                }
                if(i-1 >= 0 && j+1 < n){
                    sum = sum + M[i-1][j+1];
                    count++;
                }
                if(i+1 < m && j-1 >= 0){
                    sum = sum + M[i+1][j-1];
                    count++;
                }
                if(i+1 < m){
                    sum = sum + M[i+1][j];
                    count++;
                }
                if(j+1 < n){
                    sum = sum + M[i][j+1];
                    count++;
                }
                if(i+1 < m && j+1 < n){
                    sum = sum + M[i+1][j+1];
                    count++;
                }
                N[i][j] = sum / count;
            }
        }
        return N;
    }
};