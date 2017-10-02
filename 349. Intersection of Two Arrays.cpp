class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.size() == 0 || nums2.size() == 0) return result;
        int m1 = nums1[0];
        int m2 = nums2[0];
        int l1 = nums1[0];
        int l2 = nums2[0];
        
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] > m1) m1 = nums1[i];
            if(nums1[i] < l1) l1 = nums1[i];
        }
        for(int i = 0; i < nums2.size(); i++){
            if(nums2[i] > m2) m2 = nums2[i];
            if(nums2[i] < l2) l2 = nums2[i];
        }
        int l = l1;
        if(l2 < l) l = l2;
        int m = m1;
        if(m2 > m) m = m2;
        
        
        bool map[m-l+1];
        for(int i = 0; i < m-l+1; i++){
            map[i] = false;
        }
        for(int i = 0; i < nums1.size(); i++){
            map[nums1[i]-l] = true;
        }
        for(int i = 0; i < nums2.size(); i++){
            if(map[nums2[i]-l] == true){
                result.push_back(nums2[i]);
                map[nums2[i]-l] = false;
            }
        }
       
        return result;
    }
};