class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt=0;
        int sz=nums.size();
        k%=sz;
        
        for(int i=0;cnt<sz;i++){
            int current=i;
            int prev=nums[i];
            while(true){
                int next=(current+k)%sz;
                int tmp=nums[next];
                nums[next]=prev;
                prev=tmp;
                current=next;
                cnt++; 
                if(i==next)break;
            }
        } 
    }
};

