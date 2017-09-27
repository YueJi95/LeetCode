/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0) return true;
        quicksort(0, intervals.size()-1, intervals);
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i].end > intervals[i+1].start) return false;
        }
        return true;
    }
    
    int partition(int left, int right, int pivot, vector<Interval>& intervals){
        Interval p = intervals[pivot];
        swap(pivot, right, intervals);
        int storeindex = left;
        for(int i = left; i < right; i++){
            if(intervals[i].start < p.start){
                swap(storeindex, i, intervals);
                storeindex++;
            }
        }
        swap(storeindex, right, intervals);
        return storeindex;
    }
    
    void quicksort(int left, int right, vector<Interval>& intervals){
        if(right > left){
            int np = partition(left, right, left, intervals);
            quicksort(left, np-1, intervals);
            quicksort(np+1, right, intervals);
        }
    }
    
    void swap(int a1, int a2, vector<Interval>& intervals){
        int s = intervals[a1].start;
        int t = intervals[a1].end;
        intervals[a1].start = intervals[a2].start;
        intervals[a1].end = intervals[a2].end;
        intervals[a2].start = s;
        intervals[a2].end = t;
    }
};