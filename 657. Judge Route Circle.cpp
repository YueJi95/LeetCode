class Solution {
public:
    bool judgeCircle(string moves) {
        int Ucount = 0;
        int Dcount = 0;
        int Lcount = 0;
        int Rcount = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves.at(i) == 'U')    Ucount++;
            else if(moves.at(i) == 'D')    Dcount++;
            else if(moves.at(i) == 'L')    Lcount++;
            else    Rcount++;
        }
        return (Ucount == Dcount) && (Lcount == Rcount);
    }
};