class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>um1,um2;
        for(int i=0;i<nums1.size();i++)
            um1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
            um2[nums2[i]]++;
        
        vector<int>ret;
        for(pair<int,int>m:um1){
            if(um2[m.first]>0)
                ret.push_back(m.first);
        }
        return ret;
    }
};
