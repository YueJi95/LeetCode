class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        time = -1;
        pos = 0;
        data = vector<vector<string>*>(10);
        for(int i = 0; i < 10; i++){
            data[i] = NULL;
        }
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool result = true;
        
        if(timestamp == time){
            for(int i = 0; i < 10; i++){
                vector<string>* temp = data[(10+pos-i)%10];
                if(temp == NULL) continue;
                for(int j = 0; j < temp->size(); j++){
                    if(temp->at(j) == message){
                        result = false;
                        break;
                    }
                }
            }
            if(result == true) data[pos]->push_back(message);
        }
        else{
            for(int i = 0; i < timestamp - time; i++){
                pos = (pos + 1) % 10;
                free(data[pos]);
                data[pos] = NULL;
            }
            time = timestamp;
            vector<string>* add = new vector<string>;
            data[pos] = add;
            for(int i = 1; i < 10; i++){
                vector<string>* temp = data[(10+pos-i)%10];
                if(temp == NULL) continue;
                for(int j = 0; j < temp->size(); j++){
                    if(temp->at(j) == message){
                        result = false;
                        break;
                    }
                }
            }
            if(result == true) data[pos]->push_back(message);
        }
        return result;
    }
private:
    vector<vector<string>* > data;
    int time;
    int pos;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */