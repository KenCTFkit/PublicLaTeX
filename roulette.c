
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 160000

int judge(int a) {

  int i;
  int b[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
  int jud = 0;

  if(a == 0 || a == 37) {
    return 2; //0か00
  }
 
  for(i = 0; i < 18; i++) {
    if(b[i] == a) {
      jud = 1;
    }
  }
  if(jud == 1) {
    return 1; //黒
  } else {
    return 0; //赤
  }
    
   
}
       

  
int roulette() {

  int number = rand() % 38; //ルーレットを回す
  int bet = rand() % 2; //赤か黒をランダムで予想

  if(judge(number) == bet) {
    return 1; //勝ち
  } else {
    return 0; //負け
  }
}

int main(void)    
{

  int a, i;
  double c;
  int money;
  int win = 0;
	  
  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) {
    money = 900;
    while(1) {
      
      money--; //betした
      //printf("%d\n", money);
      a = roulette();

      if(a == 1) {
	money = money + 2;
	//printf("%d\n", money);
      }

      if(money >= 1000)
	{
	  win++;
	  break;
	} else if(money <= 0) {
	break;
      }
    
    }

  }
  
    
  printf("勝った回数は%d\n", win);
		
  c = (double)win / N;
  printf("確率は%lf\n", c);
		
  return 0;
  
}
