class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n % 2;
        n  = n / 2;
        int tem;
        while(n > 0){
            tem = n % 2;
            n = n / 2;
            if(tem == pre) return false;
            pre = tem;
        }
        return true;
    }
};