class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        int count = 1;
        int tem = 1;
        result.push_back(0);
        for(int i = 1; i <= num; i++){
            result.push_back(1 + result[i - tem]);
            count--;
            if(count == 0){
                tem = tem * 2;
                count = tem;
            }
        }
        return result;
    }
};