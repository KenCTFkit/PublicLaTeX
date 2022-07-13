#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define N 10000 //１万
//#define N 1000000 //１００万
//#define N 100000000  //１億
#define N 1000000000  //１００億

//確率分母は10!の3628800?

int height() {

  int MW[10];
  int r, swap, i;
  int leftM = -1;
  int path = 0;

  for(i = 0; i < 10; i++) {
  	MW[i] = i;
  }
	
  for(i = 9; i > 0; i--) {

  r = rand() % 10;

  swap = MW[i];

  MW[i] = MW[r];

  MW[r] = swap;

  }

  if((MW[0] % 2) == 1) { //最左端が男のときのみ

	  
	
    for(i = 1; i < 10; i++) {

      if((MW[i - 1] % 2) == 1) { //i-1が男なら
	    
	if(MW[i - 1] > leftM) { 
	  leftM = MW[i - 1];	
	}
	      
	if((MW[i] % 2) == 0) { //iが女なら
	  if(leftM < MW[i]) {
	    break;
	  } else {
	    path++;
	  }
	} else if((MW[i] % 2) == 1) { //iが男なら
	  if(leftM < MW[i]) {
	    leftM = MW[i];	    
	  }
	}

      } else { //i-1が女なら

	if((MW[i] % 2) == 0) { //iが女なら
	  if(leftM > MW[i]) { 
	    path++;
	  } else {
		break;
		}
	}
      }
	  
    }

  }

	
	
	if(path == 5) {
	  return 1;
	} else {
	  return 0;
	}

	
}
	
		

int main(void)    
{
  int i;
  double c;
  int count = 0;

  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) {
    if(height() == 1) {
      count++;
    }
  }
  
printf("条件が揃った回数は%d\n", count);		
		c = (double)count / N;
		printf("確率は%lf\n", c);
	return 0;
}

