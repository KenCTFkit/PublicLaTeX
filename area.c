
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define N 10000
#define N 1000000
//#define N 100000000
int main(void)    
{
	int i;
	double x, y, plot, pi, ans;
	int a = 0;
	int b = 0;

	srand((unsigned)time(NULL));	 

	for(i = 0; i < N; i++) {

		x = ((double)rand() / RAND_MAX) * 7;
		y = ((double)rand() / RAND_MAX) * 7;

		//printf("xは%lf, yは%lf\n", x, y);

		plot = (x * x) + (y * y);
		if(plot <= 49.0){
			a++;
			//printf("plotは%lf, a++\n", plot);
		} else {
			b++;
			//rintf("plotは%lf, b++\n", plot);
		}
	}

	

	ans = (49.0 * 4 * a) / (a + b);

	printf("半径7の円の面積は%lf\n", ans);
		
	return 0;
  
}

