class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        count = 0;
        pos = 0;
        this->size = size;
        data = new vector<int>(size);
    }
    
    double next(int val) {
        int sum = 0;
        pos = (pos + 1)% size;
        data->at(pos) = val;
        if(count < size) count++;
        for(int i = 0; i < count; i++){
            sum = sum + data->at((pos - i + size)%size);
        }
        return sum / (double)count;
    }
private:
    int count;
    int size;
    int pos;
    vector<int>* data;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */