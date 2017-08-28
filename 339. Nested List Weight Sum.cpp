/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for(int i = 0; i < nestedList.size(); i++)  q.push(nestedList[i]);
        int depth = 1;
        int count = nestedList.size();
        int bcount = 0;
        int sum = 0;
        while(q.empty() == false){
            NestedInteger current = q.front();
            q.pop();
            if(current.isInteger() == true) sum = sum + current.getInteger() * depth;
            else{
                for(int i = 0; i < current.getList().size(); i++){
                    q.push((current.getList())[i]);
                    bcount++;
                }
            }
            count--;
            if(count == 0){
                depth++;
                count = bcount;
                bcount = 0;
            }
        }
        return sum;
    }
};