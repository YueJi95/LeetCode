class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int index[100001];
        vector<int> output;
        for(int i = 0; i < B.size(); i++){
            index[B[i]] = i;
        }
        for(int i = 0; i < A.size(); i++){
            output.push_back(index[A[i]]);
        }
        return output;
    }
};