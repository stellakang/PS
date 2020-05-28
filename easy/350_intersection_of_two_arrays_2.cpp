//time complexity: O(N)
//space complexity: O(N)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return intersect(nums2, nums1);
	vector<int> inter;
        unordered_map<int,int> checker;
        
        for(int num: nums1)
            checker[num]++;
        
        for(int num: nums2){
            if(checker[num]>0){
                inter.push_back(num);
                checker[num]--;
            }
        }
        return inter;
    }
};

//time complexity: O(NlogN)
//space complexity: O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> inter;
        
        int firstIndx=0,secondIndx=0;
        int sz1=nums1.size(),sz2=nums2.size();
        
        while(firstIndx<sz1 && secondIndx<sz2){
            int n1=nums1[firstIndx];
            int n2=nums2[secondIndx];
            if(n1==n2){
                inter.push_back(n1);
                firstIndx++,secondIndx++;
            }
            else if(n1>n2)
                secondIndx++;
            else
                firstIndx++;
        }
        
        return inter;
    }
};
