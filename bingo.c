
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define M 4 //回数制限4
#define M 7 //回数制限7

//#define N 10000000
//#define N 100000000

int bingo() {

  int b[5] = {6, 5, 11, 9, 3};
  int i[5] = {16, 29, 21, 23, 17};
  int n[5] = {33, 37, 0, 34, 39};
  int g[5] = {56, 60, 47, 57, 54};
  int o[5] = {68, 66, 75, 69, 65};

  int j, k, a;

  int rd[75];
  int r, swap;
  
  for(j = 0; j < 75; j++) {
    rd[j] = j;
  }
	
  for(j = 74; j > 0; j--) {

    r = rand() % 75;

    swap = rd[j];

    rd[j] = rd[r];

    rd[r] = swap;

  }
  
  for(j = 0; j < 75; j++) {
    rd[j]++;
  }

  for(j = 0; j < M; j++) {
    
    a = rd[j];
   

    if(a < 16) {
      for(k = 0; k < 5; k++) {
	if(a == b[k]) {
	  //printf("%dに穴があいた\n", b[k]);	  
	  b[k] = 0;
	}
      }
    } else if(a < 31) {
      for(k = 0; k < 5; k++) {
	if(a == i[k]) {
	  //printf("%dに穴があいた\n", i[k]);
	  i[k] = 0;
	}
      }
    } else if(a < 46) {
      for(k = 0; k < 5; k++) {
	if(a == n[k]) {
	  //printf("%dに穴があいた\n", n[k]);	  
	  n[k] = 0;
	}
      }
    } else if(a < 61) {
      for(k = 0; k < 5; k++) {
	if(a == g[k]) {
	  //printf("%dに穴があいた\n", g[k]);	  
	  g[k] = 0;
	}
      }
    } else {
      for(k = 0; k < 5; k++) {
	if(a == o[k]) {
	  //printf("%dに穴があいた\n", o[k]);	  
	  o[k] = 0;
	}
      }
    }
  }

  //bingoの判定(１２通り)
       
  if(b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0 && b[4] == 0) { //縦
    return 1;
  } else if(i[0] == 0 && i[1] == 0 && i[2] == 0 && i[3] == 0 && i[4] == 0) { 
    return 1;
  } else if(n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0 && n[4] == 0) {
    return 1;
  } else if(g[0] == 0 && g[1] == 0 && g[2] == 0 && g[3] == 0 && g[4] == 0) {
    return 1;   
  } else if(o[0] == 0 && o[1] == 0 && o[2] == 0 && o[3] == 0 && o[4] == 0) {
    return 1;
  } else if(b[0] == 0 && i[1] == 0 && n[2] == 0 && g[3] == 0 && o[4] == 0) { //斜
    return 1;
  } else if(b[4] == 0 && i[3] == 0 && n[2] == 0 && g[1] == 0 && o[0] == 0) {
    return 1;
  } else if(b[4] == 0 && i[3] == 0 && n[2] == 0 && g[1] == 0 && o[0] == 0) { //横
    return 1;
  } else if(b[0] == 0 && i[0] == 0 && n[0] == 0 && g[0] == 0 && o[0] == 0) {
    return 1;
  } else if(b[1] == 0 && i[1] == 0 && n[1] == 0 && g[1] == 0 && o[1] == 0) {
    return 1;
  } else if(b[2] == 0 && i[2] == 0 && n[2] == 0 && g[2] == 0 && o[2] == 0) {
    return 1;   
  } else if(b[3] == 0 && i[3] == 0 && n[3] == 0 && g[3] == 0 && o[3] == 0) {
    return 1;
  } else if(b[4] == 0 && i[4] == 0 && n[4] == 0 && g[4] == 0 && o[4] == 0) {
    return 1;
  } else {
    return 0;
  }

}

int main(void)    
{
  int i;
  int win = 0;
  double c;

  srand((unsigned)time(NULL));	 

  for(i = 0; i < N; i++) {
	  
    if(bingo() == 1){
      win++;
    }
  }

  printf("試行回数は%d\n", win);
		
  c = (double)win / N;
  printf("確率は%lf\n", c);
		
  return 0;
  
}

