#include <stdio.h>
#include <math.h>

struct bar{
    int l,r,h;
};
int N,R,S,E;
bar b[1005];
double Answer;
double getPathSum();

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
	    scanf("%d%d%d",&R,&S,&E);
	    scanf("%d",&N);
	    
	    for(int i=0;i<N;i++){
	        int l,r,h;
	        scanf("%d%d%d",&l, &r, &h);
	        b[i].l = l;
	        b[i].r = r;
	        b[i].h = h;
	    }
	    Answer = getPathSum();
		printf("Case #%d\n", test_case+1);
	    printf("%.9lf\n", Answer);
	}
	return 0;
}
double getPathSum(){
    double sum = 0;
    double half = R*(M_PI);
    double left = S;
    for(int i=0;i<N;i++){
        double h = b[i].h;
        double r = b[i].r;
        double l = b[i].l;
        sum += (r - l);//left to right
        if(b[i].h>=R){
            sum += half;//half round
            sum += (h-R)*2;//go up
            sum += (l - R) - left;//left move
            left = r + R;//update left position
        }
        else{
            double cosV = (R-h)/R;
            sum += 2*acos(cosV)*R;//round part
            double dist = sqrt(2*R*h - h*h);
            sum += (l - dist) - left;//update left position
            left = r + dist;//update left position
        }
    }
    sum += E - left;
    return sum;
}
