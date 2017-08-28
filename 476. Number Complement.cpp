class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int count = 0;
        while(num > 0){
            result = result + pow(2, count) * (1 - num % 2);
            num = num / 2;
            count++;
        }
        return result;
    }
};