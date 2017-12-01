class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1) return true;
        bool matched = true;
        for(int i = 0; i < n-1; i++){
            if(matched == true){
                if(bits[i] == 1) matched = false;
            }
            else{
                matched = true;
            }
        }
        if(matched == true && bits[n-1] == 0) return true;
        else return false;
    }
};