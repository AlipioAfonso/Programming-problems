#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int D, Vf, Vg;
  double dist, Tf, Tg;
  
  while(scanf("%d %d %d", &D, &Vf, &Vg) != EOF)
  {
    dist = sqrt(12*12+D*D);
    Tf=12.0/Vf;
    Tg=dist/Vg;
    if(Tf>Tg){
      printf("S\n");
    }else{
      printf("N\n");
    }
  }
  return 0;
}
