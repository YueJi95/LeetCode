class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        data = vector<tuple<string, int> >();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool result = true;
        bool found = false;
        for(int i = 0; i < data.size(); i++){
            if(get<0>(data[i]) == message){
                found = true;
                if(get<1>(data[i]) <= timestamp - 10){
                    data[i] = make_tuple(message, timestamp);
                    break;
                }
                else{
                    result = false;
                    break;
                }
            }
        }
        if(found == false){
            data.push_back(make_tuple(message, timestamp));
        }
        return result;
    }
private:
    vector<tuple<string, int> > data;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */