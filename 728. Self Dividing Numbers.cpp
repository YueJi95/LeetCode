class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; i++){
            int val = i;
            bool flag = true;
            while(val > 0){
                int a = val % 10;
                val = val / 10;
                if(a == 0 || (i % a) != 0){
                    flag = false;
                    break;
                }
            }
            if(flag) result.push_back(i);
        }
        return result;
    }
};