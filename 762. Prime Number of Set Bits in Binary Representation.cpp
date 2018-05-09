class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        bool isPrime[31] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                               1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
                               0, 0, 1, 0, 0, 0, 0, 0, 1, 0};
        for(int i = L; i <= R; i++){
            int val = i;
            int num = 0;
            while(val > 0){
                num = num + val % 2;
                val = val / 2;
            }
            if(isPrime[num]) count++;
        }
        return count;
    }
};