/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        stack<Employee*> s;
        int count = 0;
        s.push(employees[id-1]);
        while(!s.empty()){
            Employee* temp = s.top();
            s.pop();
            count+= temp->importance; 
            for(int i = 0; i < temp->subordinates.size(); i++){
                s.push(employees[temp->subordinates[i]-1]);
            }
        }
        return count;
    }
};