class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int index = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] == '+'){
                index = i;
                break;
            }
        }
        string a1 = string(a, 0, index);
        string a2 = string(a, index+1, a.length()- index - 2);
        int x1 = stoi(a1);
        int y1 = stoi(a2);
        for(int i = 0; i < b.length(); i++){
            if(b[i] == '+'){
                index = i;
                break;
            }
        }
        a1 = string(b, 0, index);
        a2 = string(b, index+1, b.length()- index - 2);
        int x2 = stoi(a1);
        int y2 = stoi(a2);
        int x = x1 * x2 - y1* y2;
        int y = x1 * y2 + y1 * x2;
        return to_string(x) + "+" + to_string(y) + "i";
    }
};