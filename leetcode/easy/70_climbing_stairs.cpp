class Solution { 
public:
    int climbStairs(int n) {
        int twosteps=1;
        int onesteps=1;
        int steps=0;
        
        for(int i=1;i<=n;i++){
            steps=0;
            if(i-2>=0)
               steps+=twosteps;
            if(i-1>=0)
                steps+=onesteps;
            twosteps=onesteps;
            onesteps=steps;
        }
        return steps;
    }
};
