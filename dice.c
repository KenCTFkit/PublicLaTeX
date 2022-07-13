
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define N 777600 //100倍
//#define N 7776000 //1000倍
#define N 777600000 //100000倍

int dice() {

	int a[6];


	for(int i = 0; i < 6; i++) {
		a[i] = rand() % 6 + 1;
	}

	if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[3] == a[4] && a[4] == a[5] && a[5] == a[0]) {

		return(1);
	} else {
		return(0);
	}
}

	int main(void)    
	{
		int i;
		int reach = 0;
		double c;

		srand((unsigned)time(NULL));	 

		for(i = 0; i < N; i++) {
	  
			if(dice() == 1){
				reach++;
			}
		}


		printf("全部揃った回数は%d\n", reach);
		
		c = (double)reach / N;
		printf("確率は%lf\n", c);
		
		return 0;
  
	}

