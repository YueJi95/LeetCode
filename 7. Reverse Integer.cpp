class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int a = x;
        int pre = 0;
        if(a < 0){
            a = a * (-1);
            if(a < 0) return 0;
        }
        while(a != 0){
            pre = result;
            if(result < 0) return 0;
            result = result * 10;
            if(result / 10 != pre) return 0;
            if(result < 0) return 0;
            result = result + a % 10;
            if(result / 10 != pre) return 0;
            pre = result;
            a = a / 10;
            if(result < 0) return 0;
        }
        if(x < 0) result = result * (-1);
        return result;
    }
};