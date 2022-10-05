#include <cmath>
#include <cstdio>
#include <cfloat>

using namespace std;

int main(){
	int p, q, r, s, t, u;
	float min, max;
	double x, res;
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		x = 1;
		if(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u > FLT_EPSILON || p + r + u < 0){
			printf("No solution\n");
		}
		
		else{
			min = 0; max = 1;
			for(int i = 0; i < 30; i++){
				x = (min + max)/2;
				res = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
				if(res > 0) min = x;
	
				else max = x;
			}
			printf("%.4f\n", x);
		}
	}
	return 0;
}
